/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 22:52:31 by ddamaris          #+#    #+#             */
/*   Updated: 2019/12/05 22:52:59 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*f_short(t_struct *f_lst, char *s, int l, long double n)
{
	int	r;
	int j;

	j = (*s == '0') ? 2 : 0;
	while (--l >= 0 || f_lst->p-- > 0)
	{
		n *= 10.L;
		r = (int)n;
		s[j++] = r + '0';
		n -= r;
		if (!l && f_lst->p)
			s[j++] = '.';
	}
	return (s);
}

void	f_init(t_f_struct *fl, long double f)
{
	int			i;
	__uint128_t	n;

	fl->i = (f < 1) ? 0 : 1;
	fl->m = ft_strnew(64);
	n = *((__uint128_t*)(&f));
	fl->ex = (int)((n >> 64) & 0xffff) - 16383;
	i = 64;
	while (--i >= 0)
		fl->m[63 - i] = (n & ((__uint128_t)1 << i)) ? '1' : '0';
	fl->m[64] = '\0';
}

char	*f_final(char *s1, char *s2, t_f_struct *fl, int pr)
{
	int		i;
	int		l;
	char	sw;

	i = 0;
	l = ft_strlen(s1);
	while (i < l / 2)
	{
		sw = s1[i];
		s1[i] = s1[l - 1 - i];
		s1[l - 1 - i++] = sw;
	}
	if (fl->i == 1)
		s1[l++] = '.';
	i = 0;
	while (i++ < pr)
		s1[l++] = (*s2 == 0) ? '0' : *s2++;
	return (s1);
}

char	*f_long(t_struct *f_lst, char *s, int len, long double f)
{
	char		*res1;
	char		*res2;
	char		*tmp;
	t_f_struct	fl;

	f_init(&fl, f);
	tmp = ft_strnew(len + 4500);
	res2 = ft_strnew(len + 4500);
	res1 = (fl.i == 0) ? s + 2 : s;
	while (*fl.m != '\0')
	{
		if (*fl.m++ != '0')
		{
			if (fl.ex >= 0)
				res1 = str_sum(res1, str_exp(tmp, &fl));
			else if (fl.ex < 0)
				res2 = str_sum_fraction(res2, str_div(tmp, &fl));
			ft_bzero(tmp, len + 4500);
		}
		fl.ex--;
	}
	res1 = f_final(res1, res2, &fl, f_lst->p);
	free(res2);
	free(tmp);
	return (s);
}
