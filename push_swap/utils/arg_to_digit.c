/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 20:37:31 by ddamaris          #+#    #+#             */
/*   Updated: 2020/02/05 17:41:09 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		is_int(char *str)
{
	int	l;

	l = ft_strlen(str);
	if (l <= 11)
	{
		if ((*str >= '0' && *str <= '9') || *str == '-')
		{
			str++;
			while (*str)
			{
				if (!(*str >= '0' && *str <= '9'))
					return (0);
				str++;
			}
		}
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

long	ft_atoi(char *str)
{
	int		i;
	long	res;
	int		m;

	i = 0;
	res = 0;
	m = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' ||
		str[i] == '\n' || str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i - 1] == '-')
		m = -1;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	return (res * m);
}

void	sort_int(int *tab, int l)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < l - 1)
	{
		j = i;
		while (j < l)
		{
			if (tab[j] < tab[i])
			{
				tmp = tab[j];
				tab[j] = tab[i];
				tab[i] = tmp;
			}
			j++;
		}
		i++;
	}
}

int		check_double(t_stack *a)
{
	int *tmp;
	int i;

	i = -1;
	tmp = (int *)malloc(sizeof(int) * a->len);
	while (++i < a->len)
		tmp[i] = a->st[i];
	sort_int(tmp, i);
	i = -1;
	while (++i < a->len)
		if (tmp[i] == tmp[i + 1])
		{
			ft_printf("Error\n");
			return (0);
		}
	a->min = tmp[0];
	a->max = tmp[i - 1];
	a->q1 = tmp[(i - 1) / 4];
	a->q2 = tmp[(i - 1) / 2];
	a->q3 = tmp[((i - 1) * 3) / 4];
	free(tmp);
	return (1);
}
