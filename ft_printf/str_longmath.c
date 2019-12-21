/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_longmath.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 22:51:42 by ddamaris          #+#    #+#             */
/*   Updated: 2019/12/05 22:52:06 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_sum_fraction(char *res, char *s2)
{
	int k;
	int i;
	int n;

	k = 0;
	i = ft_strlen(s2) - 1;
	while (i >= 0)
	{
		res[i] += (res[i] == 0) ? 48 : 0;
		n = (res[i] - 48) + (s2[i] - 48) + k;
		if ((n) < 10)
		{
			k = 0;
			res[i] = n + 48;
		}
		else
		{
			res[i] = n - 10 + 48;
			k = 1;
		}
		i--;
	}
	return (res);
}

char	*str_sum(char *res, char *s2)
{
	int	k;
	int	i;
	int n;

	i = 0;
	k = 0;
	while (s2[i])
	{
		res[i] += (res[i] == 0) ? 48 : 0;
		n = (res[i] - 48) + (s2[i] - 48) + k;
		if ((n) < 10)
		{
			k = 0;
			res[i++] = n + 48;
		}
		else
		{
			res[i++] = n - 10 + 48;
			k = 1;
			s2[i] += (s2[i] == 0) ? 48 : 0;
		}
	}
	return (res);
}

char	*str_div(char *tmp, t_f_struct *fl)
{
	int j;
	int nb;
	int i;
	int k;

	i = 1;
	tmp[0] = '5';
	while (i < -fl->ex)
	{
		j = 0;
		k = 0;
		while (tmp[j] == '0')
			j++;
		while (tmp[j])
		{
			nb = (tmp[j] - 48) + k;
			if ((nb / 2) != 0 && (tmp[j++] = (nb / 2) + 48))
				k = (nb % 2) ? 10 : 0;
			else if ((nb / 2) == 0 && (tmp[j++] = '0'))
				k = (nb == 0) ? 0 : 10;
			tmp[j] += (k == 10 && tmp[j] == 0) ? 48 : 0;
		}
		i++;
	}
	return (tmp);
}

char	*str_exp(char *tmp, t_f_struct *fl)
{
	int	k;
	int	j;
	int	nb;
	int	i;

	tmp[0] = '1';
	i = fl->ex;
	while (i-- > 0)
	{
		j = 0;
		k = 0;
		while (tmp[j])
		{
			nb = (tmp[j] - 48) * 2 + k;
			if (nb < 10 && (tmp[j++] = nb + 48))
				k = 0;
			else if (nb > 9 && (tmp[j++] = nb - 10 + 48))
			{
				k = 1;
				tmp[j] += (tmp[j] == 0) ? 48 : 0;
			}
		}
	}
	return (tmp);
}
