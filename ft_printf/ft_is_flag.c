/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:49:34 by ddamaris          #+#    #+#             */
/*   Updated: 2019/11/13 18:39:51 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_if_hash(t_struct *f_lst, unsigned long long d)
{
	int	l;

	l = 0;
	if (f_lst->hash && (d != 0 || f_lst->p) && f_lst->f_type == 'x')
		l = write(f_lst->fd, "0x", 2);
	if (f_lst->hash && d != 0 && f_lst->f_type == 'X')
		l = write(f_lst->fd, "0X", 2);
	if (f_lst->hash && d != 0 && f_lst->f_type == 'o' && f_lst->prec <= 0)
		l = write(f_lst->fd, "0", 1);
	return (l);
}

int	is_lh(const char *f, t_struct *f_lst)
{
	if (*f == 'z' || *f == 'j')
		f_lst->zj = (*f == 'z') ? 'z' : 'j';
	if (!f_lst->zj)
	{
		if (*f == 'h' && *(f + 1) != 'h' && *(f - 1) != 'h')
			f_lst->hl = 1;
		else if (*f == 'h' && *(f + 1) == 'h')
		{
			f_lst->hl = 2;
			return (2);
		}
		else if (*f == 'l' && *(f + 1) != 'l' && *(f - 1) != 'l')
			f_lst->hl = 3;
		else if (*f == 'l' && *(f + 1) == 'l')
		{
			f_lst->hl = 4;
			return (2);
		}
	}
	else
		f_lst->hl = 4;
	if (*f == 'L')
		f_lst->hl = 5;
	return (1);
}

int	is_number(const char *f, t_struct *f_lst)
{
	int	ln;

	ln = 0;
	if (*f == '*')
	{
		f_lst->width = va_arg(f_lst->ap, int);
		if (f_lst->width < 0)
		{
			f_lst->width *= -1;
			f_lst->minus = '-';
		}
		return (1);
	}
	f_lst->width = 0;
	while (*f >= 48 && *f <= 57)
	{
		f_lst->width = f_lst->width * 10 + (*f - '0');
		f++;
		ln++;
	}
	return (ln);
}

int	is_prec(const char *f, t_struct *f_lst)
{
	int	ln;

	f++;
	if (*f == '*')
	{
		f_lst->prec = va_arg(f_lst->ap, int);
		if (f_lst->prec < 0)
			f_lst->prec = -1;
		return (1);
	}
	ln = 0;
	f_lst->prec = 0;
	if (*f < '0' || *f > '9')
		return (0);
	while (*f >= 48 && *f <= 57)
	{
		f_lst->prec = f_lst->prec * 10 + (*f - '0');
		f++;
		ln++;
	}
	return (ln);
}

int	is_flag(const char *format, t_struct *f_lst)
{
	int	ln;

	ln = 0;
	if (*format == '#')
		f_lst->hash = '#';
	else if (*format == '0')
		f_lst->zero = '0';
	else if (*format == '-')
		f_lst->minus = '-';
	else if (*format == '+' || *format == ' ')
		f_lst->sign = (*format != '+' && f_lst->sign != '+') ? ' ' : '+';
	else if (*format == 'l' || *format == 'h' || *format == 'L')
		ln = is_lh(format, f_lst) - 1;
	else if ((*format >= 49 && *format <= 57) || *format == '*')
		ln = is_number(format, f_lst) - 1;
	else if (*format == '.')
		ln = is_prec(format, f_lst);
	else if (*format == 'z' || *format == 'j')
		ln = is_lh(format, f_lst) - 1;
	else
		return (0);
	ln++;
	return (ln);
}
