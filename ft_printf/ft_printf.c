/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:45:26 by ddamaris          #+#    #+#             */
/*   Updated: 2019/11/13 18:23:12 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flst(t_struct *f_lst)
{
	f_lst->minus = 0;
	f_lst->hash = 0;
	f_lst->zero = ' ';
	f_lst->width = 0;
	f_lst->prec = -1;
	f_lst->hl = 0;
	f_lst->p = 0;
	f_lst->f_type = 0;
	f_lst->base = 10;
	f_lst->size = 0;
	f_lst->len = 0;
	f_lst->sign = 0;
	f_lst->zj = 0;
}

int		ft_parse(const char *str, t_struct *f_lst)
{
	int		length;

	length = 0;
	init_flst(f_lst);
	while ((length = is_flag(str, f_lst)) != 0)
	{
		f_lst->len += length;
		str += length;
	}
	if (*str != '\0')
	{
		f_lst->f_type = *str;
		f_lst->len++;
	}
	f_lst->len++;
	length = ft_work_out(f_lst);
	return (length);
}

int		ft_prn_str(const char *s, int fd)
{
	int		l;

	l = 0;
	while (s[l] != '%' && s[l] != '\0')
		l++;
	write(fd, s, l);
	return (l);
}

int		ft_printf(const char *format, ...)
{
	int			length;
	t_struct	f_lst;

	length = 0;
	f_lst.fd = 1;
	va_start(f_lst.ap, format);
	while (*format != '\0')
	{
		if (*format != '%')
			length += (f_lst.len = ft_prn_str(format, f_lst.fd));
		else
			length += ft_parse(format + 1, &f_lst);
		format += f_lst.len;
	}
	va_end(f_lst.ap);
	return (length);
}
