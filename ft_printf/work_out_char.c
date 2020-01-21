/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_out_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:52:40 by ddamaris          #+#    #+#             */
/*   Updated: 2019/11/13 18:24:32 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_transform(char *src, int l)
{
	char	*dst;
	int		i;
	int		j;

	dst = (char *)malloc(sizeof(char) * (l + 1));
	dst[l] = 0;
	i = 0;
	j = 0;
	while (src[i])
	{
		if (src[i] <= 31 && src[i] > 0)
		{
			dst[j++] = '\\';
			dst[j++] = src[i] / 10 + 48;
			dst[j++] = src[i] % 10 + 48;
		}
		dst[j++] = src[i];
		i++;
	}
	return (dst);
}

int		work_out_char(t_struct *f_lst)
{
	int		length;
	char	c;

	c = (char)va_arg(f_lst->ap, int);
	length = 0;
	if (f_lst->minus != '-' && f_lst->width > 1)
		while ((f_lst->width)-- - 1)
			length += write(f_lst->fd, &f_lst->zero, 1);
	length += write(f_lst->fd, &c, 1);
	if (f_lst->width > 1 && f_lst->minus == '-')
		while ((f_lst->width)-- - 1)
			length += write(f_lst->fd, " ", 1);
	return (length);
}

int		work_out_any_char(t_struct *f_lst)
{
	int		length;

	length = 0;
	if (f_lst->minus != '-' && f_lst->width > 1)
		while ((f_lst->width)-- - 1)
			length += write(f_lst->fd, &f_lst->zero, 1);
	if (f_lst->f_type != '\0' && f_lst->f_type != 'z' && f_lst->f_type != 'j')
		length += write(f_lst->fd, &f_lst->f_type, 1);
	if (f_lst->width > 1 && f_lst->minus == '-')
		while ((f_lst->width)-- - 1)
			length += write(f_lst->fd, " ", 1);
	return (length);
}

int		work_out_str(t_struct *f_lst)
{
	int		length;
	size_t	ln;
	char	*s;
	char	*res;

	s = va_arg(f_lst->ap, char *);
	if (!s)
		s = "(null)";
	length = 0;
	ln = (f_lst->f_type == 'k') ? ft_strlen_k(s) : ft_strlen(s);
	res = (f_lst->f_type == 'k') ? str_transform(s, ln) : s;
	if (f_lst->prec < (int)ln && f_lst->prec >= 0)
		ln = f_lst->prec;
	if (f_lst->minus != '-' && f_lst->width > (int)ln)
		while ((f_lst->width)-- - ln)
			length += write(f_lst->fd, &f_lst->zero, 1);
	length += write(f_lst->fd, res, ln);
	if (f_lst->width > (int)ln && f_lst->minus == '-')
		while ((f_lst->width)-- - ln)
			length += write(f_lst->fd, " ", 1);
	if (f_lst->f_type == 'k')
		free(res);
	return (length);
}
