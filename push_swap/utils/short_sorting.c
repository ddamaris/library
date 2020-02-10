/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:31:31 by ddamaris          #+#    #+#             */
/*   Updated: 2020/02/05 17:48:01 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	final_sorting(t_stack *a, t_stack *b, t_flags *f)
{
	int i;

	find_min(a);
	i = find_index_of_elem(a->min, a->st, a->len);
	if (i <= (a->len - i))
	{
		while (i > 0)
		{
			r('a', a, b, f);
			i--;
		}
	}
	else
	{
		while (i < a->len)
		{
			rv('a', a, b, f);
			i++;
		}
	}
}

void	sort_3(t_stack *a, t_stack *b, t_flags *f)
{
	if (a->len == 1)
		return ;
	if (a->len == 2)
	{
		if (a->st[0] > a->st[1])
			s('a', a, b, f);
		return ;
	}
	else if (a->len == 3)
	{
		a->max = find_max(a);
		a->i_max = find_index_of_elem(a->max, a->st, a->len);
		if ((a->i_max == 0 && (a->st[1] < a->st[2])) ||
			(a->i_max == 1 && (a->st[2] < a->st[0])))
			return ;
		else if (a->i_max == 0 && (a->st[1] > a->st[2]))
			r('a', a, b, f);
		else if (a->i_max == 1 && (a->st[2] > a->st[0]))
			rv('a', a, b, f);
		if (a->st[0] > a->st[1])
			s('a', a, b, f);
	}
}

void	short_sort(t_stack *a, t_stack *b, t_flags *f)
{
	if (a->len < 4)
		sort_3(a, b, f);
	else if (a->len < 5)
	{
		p('b', a, b, f);
		b->rp = 0;
		sort_3(a, b, f);
		put_to_right_place(a, b, f);
	}
	else if (a->len < 6)
	{
		p('b', a, b, f);
		p('b', a, b, f);
		sort_3(a, b, f);
		find_right_number(a, b);
		put_to_right_place(a, b, f);
		b->rp = 0;
		put_to_right_place(a, b, f);
	}
}
