/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_out_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:53:15 by ddamaris          #+#    #+#             */
/*   Updated: 2019/11/13 18:27:49 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_number(long long nb, int base)
{
	int			l;

	l = 1;
	nb /= base;
	while (nb)
	{
		l++;
		nb /= base;
	}
	return (l);
}

int	len_digit(t_struct *f_lst, long long nb)
{
	int			l;
	int			tmp;

	l = len_number(nb, f_lst->base);
	if (f_lst->prec > l)
	{
		tmp = (f_lst->prec - l);
		l = f_lst->prec;
		f_lst->prec = tmp;
	}
	else if (nb == 0 && f_lst->prec == 0)
	{
		f_lst->prec = -2;
		l = 0;
	}
	else if (f_lst->prec != -1)
		f_lst->prec = 0;
	if (f_lst->sign)
		l++;
	return (l);
}

int	print_before(t_struct *f_lst, long long d)
{
	size_t		ln;

	ln = 0;
	f_lst->size = len_digit(f_lst, d);
	if (f_lst->minus == '-' || (f_lst->zero == '0' && f_lst->prec == -1))
		ln += (f_lst->sign) ? write(f_lst->fd, &f_lst->sign, 1) : 0;
	while (f_lst->minus != '-' && f_lst->size < f_lst->width--)
		ln += (f_lst->prec != -1) ? write(f_lst->fd, " ", 1) :
			write(f_lst->fd, &f_lst->zero, 1);
	if (f_lst->minus != '-' && !(f_lst->zero == '0' && f_lst->prec == -1))
		ln += (f_lst->sign) ? write(f_lst->fd, &f_lst->sign, 1) : 0;
	return ((int)ln);
}

int	print_digit(t_struct *f_lst, long long d)
{
	int			l;
	char		ch;

	l = 0;
	if ((d + 1) == -9223372036854775807)
	{
		l += write(f_lst->fd, "9223372036854775808", 19);
		return (l);
	}
	if (f_lst->prec > -2)
	{
		if (d == 0)
		{
			l += write(f_lst->fd, "0", 1);
			return (l);
		}
		if (d / f_lst->base)
			print_digit(f_lst, d / f_lst->base);
		ch = d % f_lst->base + '0';
		l += write(f_lst->fd, &ch, 1);
	}
	return (l);
}

int	work_out_digit(t_struct *f_lst)
{
	int			l;
	long long	d;

	if (f_lst->hl == 4)
		d = va_arg(f_lst->ap, long long);
	else if (f_lst->hl == 3)
		d = va_arg(f_lst->ap, long);
	else if (f_lst->hl == 1)
		d = (short)va_arg(f_lst->ap, int);
	else if (f_lst->hl == 2)
		d = (char)va_arg(f_lst->ap, int);
	else
		d = va_arg(f_lst->ap, int);
	f_lst->sign = (d < 0) ? '-' : f_lst->sign + 0;
	d *= (d >= 0) ? 1 : (-1);
	l = print_before(f_lst, d);
	while (f_lst->prec != -1 && f_lst->prec-- > 0)
		l += write(f_lst->fd, "0", 1);
	l += (f_lst->prec <= -2) ? 0 : len_number(d, f_lst->base);
	print_digit(f_lst, d);
	while (f_lst->minus == '-' && f_lst->size < f_lst->width--)
		l += write(f_lst->fd, " ", 1);
	return (l);
}
