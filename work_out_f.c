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

char	*final_f_str(char *s, char hash)
{
	size_t	i;
	char	*tmp;

	i = ft_strlen(s) - 1;
	if (s[i - 1] == '.' && hash != '#')
		i--;
	tmp = s;
	s = ft_strnew(i);
	while (i--)
		s[i] = tmp[i];
	free(tmp);
	return (s);
}

char	*round_f(t_struct *f_lst, char *s)
{
	size_t	i;
	int		round;

	i = ft_strlen(s);
	round = 1;
	while (round)
	{
		if (s[--i] >= '5' && s[i] <= '9')
		{
			if (s[i - 1] == '.')
				i--;
			if (s[i - 1] < '9' && (s[i - 1] += 1))
				round = 0;
			if (s[i] == '.')
				s[i + 1] = '0';
			else
				s[i] = '0';
		}
		else if (s[i] >= '0' && s[i] < '5')
			round = 0;
	}
	s = final_f_str(s, f_lst->hash);
	return (s);
}

char 	*f_to_str(t_struct *f_lst, double long *dp, char *s, int i)
{
	__uint128_t	n;
	int			j;
	char 		f_str[80];
	double long	nb;

	j = i + f_lst->prec;
	nb = *dp;
	while (j--)
		nb *= 10;
	n = (__uint128_t)(nb);
	j = 79;
	while (j >= 0)
	{
		if ((n & ((__uint128_t)1 << j)) != 0)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		if (j == 79 || j == 64)
			write(1, " | ", 3);
		j--;
	}

	return (s);
}


char	*ft_ftoa(t_struct *f_lst, double long *dp, char *s)
{
	int			i;
	int			j;
	int			r;

	i = 0;
	j = 0;
	while (*dp >= 1.L && (*dp /= 10.L))
		i++;
	s = ft_strnew(i + f_lst->prec + 2);
	if (i == 0 && (*s++ = '0'))
		*s++ = '.';
	if (f_lst->prec <= 18)
		s = f_to_str(f_lst, dp, s, i);
	else
		while (--i >= 0 || f_lst->prec-- > 0)
		{
			*dp *= 10.L;
			r = (int)*dp;
			s[j++] = r + '0';
			*dp -= r;
			if (!i && f_lst->prec)
				s[j++] = '.';
		}
	s = round_f(f_lst, s);
	return (s);
}

int		print_before_f(t_struct *f_lst, char *s)
{
	size_t	ln;

	ln = 0;
	f_lst->size = (f_lst->sign) ? ft_strlen(s) + 1 : ft_strlen(s);
	if (f_lst->minus == '-' || (f_lst->zero == '0' && f_lst->prec == -1))
		ln += (f_lst->sign) ? write(f_lst->fd, &f_lst->sign, 1) : 0;
	while (f_lst->minus != '-' && f_lst->size < f_lst->width--)
		ln += (f_lst->prec >= 0) ? write(f_lst->fd, " ", 1) :
			write(f_lst->fd, &f_lst->zero, 1);
	if (f_lst->minus != '-' && !(f_lst->zero == '0' && f_lst->prec == -1))
		ln += (f_lst->sign) ? write(f_lst->fd, &f_lst->sign, 1) : 0;
	return ((int)ln);
}

int		work_out_f(t_struct *f_lst)
{
	char		*res;
	int			l;
	double long	d;

	l = 0;
	res = NULL;
	if (f_lst->hl == 5)
		d = va_arg(f_lst->ap, double long);
	else
		d = va_arg(f_lst->ap, double);
	if (d < 0 && (d *= -1))
		f_lst->sign = '-';
	if (f_lst->prec == -1)
		f_lst->prec = 6;
	f_lst->prec++;
	res = ft_ftoa(f_lst, &d, res);
	l += print_before_f(f_lst, res);
	l += write(f_lst->fd, res, ft_strlen(res));
	while (f_lst->minus == '-' && f_lst->size < f_lst->width--)
		l += write(f_lst->fd, " ", 1);
	free(res);
	return (l);
}
