/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_out_uxo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:12:15 by ddamaris          #+#    #+#             */
/*   Updated: 2019/11/13 18:35:42 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_number_u(unsigned long long nb, int base)
{
	int		l;

	l = 1;
	nb /= base;
	while (nb)
	{
		l++;
		nb /= base;
	}
	return (l);
}

int	len_digit_u(t_struct *f_lst, unsigned long long nb)
{
	int		l;
	int		tmp;

	l = len_number_u(nb, f_lst->base);
	if (f_lst->prec > l)
	{
		tmp = (f_lst->prec - l);
		l = f_lst->prec;
		f_lst->prec = tmp;
	}
	else if (nb == 0 && f_lst->prec == 0 &&
		!(f_lst->f_type == 'o' && f_lst->hash))
	{
		f_lst->prec = -2;
		l = 0;
	}
	else if (f_lst->prec != -1)
		f_lst->prec = 0;
	l += (f_lst->hash && (nb != 0 || f_lst->p) &&
		(f_lst->f_type == 'x' || f_lst->f_type == 'X')) ? 2 : 0;
	l += (f_lst->hash && nb != 0 && f_lst->f_type == 'o' &&
		f_lst->prec <= 0) ? 1 : 0;
	return (l);
}

int	print_before_u(t_struct *f_lst, unsigned long long d)
{
	size_t	ln;

	ln = 0;
	f_lst->size = len_digit_u(f_lst, d);
	if (f_lst->minus == '-' || (f_lst->zero == '0' && f_lst->prec == -1))
		ln += print_if_hash(f_lst, d);
	while (f_lst->minus != '-' && f_lst->size < f_lst->width--)
		ln += (f_lst->prec != -1) ?
			write(f_lst->fd, " ", 1) : write(1, &f_lst->zero, 1);
	if (f_lst->minus != '-' && !(f_lst->zero == '0' && f_lst->prec == -1))
		ln += print_if_hash(f_lst, d);
	return ((int)ln);
}

int	print_digit_u(t_struct *f_lst, unsigned long long d)
{
	int				l;
	unsigned char	ch;

	l = 0;
	if (f_lst->prec > -2)
	{
		if (d == 0)
		{
			l += write(f_lst->fd, "0", 1);
			return (l);
		}
		if (d / f_lst->base)
			print_digit_u(f_lst, d / f_lst->base);
		ch = (d % f_lst->base < 10)
			? (d % f_lst->base + '0')
			: (d % f_lst->base - 10 + 'a');
		if (ch > '9')
			ch -= (f_lst->f_type == 'X') ? 32 : 0;
		l += write(f_lst->fd, &ch, 1);
	}
	return (l);
}

int	work_out_uxo(t_struct *f_lst)
{
	int					l;
	unsigned long long	d;

	if (f_lst->hl == 4)
		d = va_arg(f_lst->ap, unsigned long long);
	else if (f_lst->hl == 3)
		d = va_arg(f_lst->ap, unsigned long);
	else if (f_lst->hl == 1)
		d = (unsigned short)va_arg(f_lst->ap, unsigned int);
	else if (f_lst->hl == 2)
		d = (unsigned char)va_arg(f_lst->ap, unsigned int);
	else
		d = va_arg(f_lst->ap, unsigned int);
	if (f_lst->f_type == 'o' || f_lst->f_type == 'x' || f_lst->f_type == 'X')
		f_lst->base = (f_lst->f_type == 'o') ? 8 : 16;
	l = print_before_u(f_lst, d);
	while (f_lst->prec != -1 && f_lst->prec-- > 0)
		l += write(f_lst->fd, "0", 1);
	l += (f_lst->prec <= -2) ? 0 : len_number_u(d, f_lst->base);
	print_digit_u(f_lst, d);
	while (f_lst->minus == '-' && f_lst->size < f_lst->width--)
		l += write(f_lst->fd, " ", 1);
	return (l);
}
