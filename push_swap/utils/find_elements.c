/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:42:31 by ddamaris          #+#    #+#             */
/*   Updated: 2020/02/05 17:56:33 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		find_index_of_elem(int el, int *stack, int len)
{
	int	i;

	if (len == 0)
		return (-1);
	i = 0;
	while (stack[i] != el)
		i++;
	return (i);
}

void	find_min(t_stack *st)
{
	int	i;

	i = 1;
	st->min = st->st[0];
	st->i_min = 0;
	while (i < st->len)
	{
		if (st->min > st->st[i])
		{
			st->min = st->st[i];
			st->i_min = i;
		}
		i++;
	}
}

int		find_max(t_stack *st)
{
	int	i;
	int	mx;

	i = 1;
	mx = st->st[0];
	while (i < st->len)
	{
		if (mx < st->st[i])
			mx = st->st[i];
		i++;
	}
	return (mx);
}

void	find_right_place(t_stack *st, int nb)
{
	int	i;

	i = 0;
	find_min(st);
	while (!(nb > st->st[i] && nb < st->st[i + 1]) && i < (st->len - 1))
		i++;
	if (i < st->len - 1)
		st->rp = i + 1;
	else if (nb > st->st[st->len - 1] && nb < st->st[0])
		st->rp = 0;
	else
		st->rp = st->i_min;
}

void	search_in_b(t_stack *a, t_stack *b, int min)
{
	int	i;

	i = -1;
	while (++i < b->len)
	{
		if (b->st[i] >= min)
		{
			find_right_place(a, b->st[i]);
			if (a->rp <= (a->len - a->rp) && i <= (b->len - i))
				b->q1 = (a->rp > i) ? a->rp : i;
			else if (a->rp > (a->len - a->rp) && i > (b->len - i))
				b->q1 = ((a->len - a->rp) > (b->len - i)) ?
					(a->len - a->rp) : (b->len - i);
			else if (a->rp <= (a->len - a->rp) && i > (b->len - i))
				b->q1 = a->rp + (b->len - i);
			else if (a->rp > (a->len - a->rp) && i <= (b->len - i))
				b->q1 = a->len - a->rp + i;
			if (b->q1 < b->q3 && (b->q3 = b->q1))
				b->rp = i;
			if (b->q1 == b->q3 && (b->st[i] > b->st[b->rp]))
				b->rp = i;
		}
	}
}
