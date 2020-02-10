/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 20:25:50 by ddamaris          #+#    #+#             */
/*   Updated: 2020/02/05 17:53:18 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		parsing(char **av, t_flags *flags)
{
	int i;

	i = 1;
	flags->c = 0;
	flags->v = 0;
	while (av[i][0] == '-')
	{
		if (av[i][1] == 'c')
			flags->c = 1;
		else if (av[i][1] == 'v')
			flags->v = 1;
		else
		{
			ft_printf("%sInvalid option: -%c\n", RED, av[i][1]);
			return (0);
		}
		i++;
	}
	return (i);
}

int		is_right_number(char *arg, int *nb)
{
	long	tmp_nb;

	if (is_int(arg))
	{
		tmp_nb = ft_atoi(arg);
		if (tmp_nb >= -2147483648 && tmp_nb <= 2147483647)
			*nb = (int)tmp_nb;
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

int		stack_init(char **av, int l, t_stack *a)
{
	int	i;
	int	j;
	int	nb;

	i = 1;
	j = 0;
	nb = 0;
	while (av[i][0] == '-' && (av[i][1] < '0' || av[i][1] > '9'))
		i++;
	if (!(a->st = (int *)malloc(sizeof(int) * (l - i))))
		return (0);
	while (j < (l - i))
	{
		if (is_right_number(av[i + j], &nb))
			a->st[j++] = nb;
		else
		{
			ft_printf("Error\n");
			return (0);
		}
	}
	a->len = j;
	return (1);
}

int		check_init(t_stack *a, t_stack *b, int ac, char **av)
{
	if (!(stack_init(av, ac, a)))
		return (0);
	if (!(check_double(a)))
		return (0);
	if (!(b->st = (int *)malloc(sizeof(int) * (a->len - 1))))
		return (0);
	a->opnb = 0;
	b->len = 0;
	return (1);
}

int		is_sorted(t_stack *st)
{
	int	i;

	i = -1;
	find_min(st);
	if (st->i_min == 0)
	{
		while (++i < st->len - 1)
			if (st->st[i] > st->st[i + 1])
				return (0);
	}
	else
	{
		if (st->st[0] < (st->st[st->len - 1]))
			return (0);
		while (++i < st->i_min - 1)
			if (st->st[i] > st->st[i + 1])
				return (0);
		while (++i < st->len - 1)
			if (st->st[i] > st->st[i + 1])
				return (0);
	}
	return (1);
}
