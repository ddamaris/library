/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:45:31 by ddamaris          #+#    #+#             */
/*   Updated: 2020/02/05 18:05:33 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		find_in_top(t_stack *a, t_stack *b, int q)
{
	int	mn;
	int mx;
	int i;

	i = 0;
	if (q == 0 && (mx = a->q1))
		mn = a->min + 1;
	else if (q == 1 && (mx = a->q2))
		mn = a->q1 + 1;
	else if (q == 2 && (mx = a->q3))
		mn = a->q2 + 1;
	else if (q == 3 && (mx = a->max - 1))
		mn = a->q3 + 1;
	while (i < a->len)
	{
		if (a->st[i] >= mn && a->st[i] <= mx)
		{
			b->min = a->st[i];
			b->i_min = i;
			return (1);
		}
		i++;
	}
	return (0);
}

int		find_in_bottom(t_stack *a, t_stack *b, int q)
{
	int	mn;
	int mx;
	int i;

	i = a->len - 1;
	if (q == 0 && (mx = a->q1))
		mn = a->min + 1;
	else if (q == 1 && (mx = a->q2))
		mn = a->q1 + 1;
	else if (q == 2 && (mx = a->q3))
		mn = a->q2 + 1;
	else if (q == 3 && (mx = a->max - 1))
		mn = a->q3 + 1;
	while (i >= 0)
	{
		if (a->st[i] >= mn && a->st[i] <= mx)
		{
			b->max = a->st[i];
			b->i_max = i;
			return (1);
		}
		i--;
	}
	return (0);
}

void	fill_b(t_stack *a, t_stack *b, t_flags *f)
{
	int i;

	i = 0;
	while (i < 4)
	{
		while ((find_in_top(a, b, i)) && (find_in_bottom(a, b, i)) &&
			a->len > 4)
		{
			a->rp = (b->i_min <= (a->len - b->i_max)) ? b->i_min : b->i_max;
			if (b->i_min <= (a->len - b->i_max))
				go_to_top('a', a, b, f);
			else
				go_to_bottom('a', a, b, f);
			p('b', a, b, f);
		}
		i++;
	}
}

void	find_right_number(t_stack *a, t_stack *b)
{
	b->rp = 0;
	if (b->st[0] >= a->q3 || b->st[b->len - 1] >= a->q3)
		search_in_b(a, b, a->q3);
	else if (b->st[0] >= a->q2 || b->st[b->len - 1] >= a->q2)
		search_in_b(a, b, a->q2);
	else if (b->st[0] >= a->q1 || b->st[b->len - 1] >= a->q1)
		search_in_b(a, b, a->q1);
	else
		search_in_b(a, b, a->min);
}

void	long_sort(t_stack *a, t_stack *b, t_flags *f)
{
	fill_b(a, b, f);
	short_sort(a, b, f);
	while (b->len)
	{
		b->q3 = 7000;
		b->rp = 0;
		find_right_number(a, b);
		find_right_place(a, b->rp);
		if ((a->rp <= (a->len - a->rp)) && (b->rp <= (b->len - b->rp)))
			go_both_to_top(a, b, f);
		else if ((a->rp > (a->len - a->rp)) && (b->rp > (b->len - b->rp)))
			go_both_to_bottom(a, b, f);
		else
		{
			if (b->rp <= (b->len - b->rp))
				go_to_top('b', a, b, f);
			else
				go_to_bottom('b', a, b, f);
		}
		put_to_right_place(a, b, f);
	}
}
