/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_out_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:06:26 by ddamaris          #+#    #+#             */
/*   Updated: 2019/11/21 14:07:01 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*round_f(char *s)
{
	size_t	i;

	i = ft_strlen(s) - 2;
	s[i + 2] = '\0';
	if (s[i] >= '5' && s[i] <= '9')
	{
		i -= (s[i - 1] == '.') ? 1 : 0;
		while (s[i - 1] == '9')
		{
			s[--i] = '0';
			i -= (s[i - 1] == '.') ? 1 : 0;
		}
		i -= (s[i - 1] == '.') ? 1 : 0;
		s[i - 1] += 1;
	}
	return (s);
}

char	*f_to_str(t_struct *f_lst, long double nb, char *s)
{
	int			i;
	int			j;
	long double	n;

	i = 0;
	j = 0;
	n = nb;
	while (n >= 1.L && (n /= 10.L))
		i++;
	s = ft_strnew(i + f_lst->p + 2);
	if (i == 0 && (s[j++] = '0'))
		s[j++] = '.';
	if ((i + f_lst->prec) < 8)
		s = f_short(f_lst, s, i, n);
	else
		s = f_long(f_lst, s, i + f_lst->p, nb);
	s = round_f(s);
	return (s);
}

char	*ft_ftoa(t_struct *f_lst, long double *dp, char *s)
{
	int	i;

	i = 0;
	if (isinf(*dp))
	{
		s = "inf";
		f_lst->zero = ' ';
	}
	else if (isnan(*dp))
	{
		s = "nan";
		f_lst->sign = 0;
		f_lst->zero = ' ';
	}
	else
	{
		s = f_to_str(f_lst, *dp, s);
		i = (int)(ft_strlen(s)) - 2;
		s[i--] = '\0';
		if (s[i] == '.' && f_lst->hash != '#')
			s[i] = '\0';
		if (s[0] == '0' && s[1] != '.' && s[1] != 0)
			s = ft_increase_str(s);
	}
	return (s);
}

int		print_f(t_struct *f_lst, char *s)
{
	size_t	ln;
	int		i;

	ln = 0;
	i = ft_strlen(s);
	f_lst->size = (f_lst->sign) ? i + 1 : i;
	if (f_lst->minus == '-' || f_lst->zero == '0')
		ln += (f_lst->sign) ? write(f_lst->fd, &f_lst->sign, 1) : 0;
	while (f_lst->minus != '-' && f_lst->size < f_lst->width--)
		ln += write(f_lst->fd, &f_lst->zero, 1);
	if (f_lst->minus != '-' && f_lst->zero != '0')
		ln += (f_lst->sign) ? write(f_lst->fd, &f_lst->sign, 1) : 0;
	ln += write(f_lst->fd, s, i);
	while (f_lst->minus == '-' && f_lst->size < f_lst->width--)
		ln += write(f_lst->fd, " ", 1);
	return ((int)ln);
}

int		work_out_f(t_struct *f_lst)
{
	char		*res;
	int			l;
	long double	d;

	l = 0;
	res = NULL;
	if (f_lst->hl == 5)
		d = va_arg(f_lst->ap, long double);
	else
		d = va_arg(f_lst->ap, double);
	if (d < 0 || 5 / d == -INFINITY || d == -INFINITY)
	{
		d *= -1;
		f_lst->sign = '-';
	}
	if (d == DBL_MIN || d == LDBL_MIN)
		d = 0.l;
	if (f_lst->prec < 0)
		f_lst->prec = 6;
	f_lst->p = f_lst->prec + 2;
	res = ft_ftoa(f_lst, &d, res);
	l += print_f(f_lst, res);
	return (l);
}
