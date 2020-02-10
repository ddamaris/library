/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_support1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:42:31 by ddamaris          #+#    #+#             */
/*   Updated: 2020/02/05 17:49:42 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	go_to_top(char ch, t_stack *a, t_stack *b, t_flags *f)
{
	int	i;

	i = (ch == 'a') ? a->rp : b->rp;
	while (i > 0)
	{
		r(ch, a, b, f);
		i--;
	}
}

void	go_both_to_top(t_stack *a, t_stack *b, t_flags *f)
{
	while (a->rp && b->rp)
	{
		rr(a, b, f);
		a->rp--;
		b->rp--;
	}
}

void	go_to_bottom(char ch, t_stack *a, t_stack *b, t_flags *f)
{
	int i;
	int l;

	i = (ch == 'a') ? a->rp : b->rp;
	l = (ch == 'a') ? a->len : b->len;
	while (i < l)
	{
		rv(ch, a, b, f);
		i++;
	}
}

void	go_both_to_bottom(t_stack *a, t_stack *b, t_flags *f)
{
	int i;
	int l;

	i = 0;
	l = 0;
	if (a->len - a->rp < b->len - b->rp)
	{
		i = a->rp;
		l = a->len;
	}
	else
	{
		i = b->rp;
		l = b->len;
	}
	while (i < l)
	{
		rrv(a, b, f);
		i++;
	}
}

void	put_to_right_place(t_stack *a, t_stack *b, t_flags *f)
{
	find_right_place(a, b->st[0]);
	if (a->rp == 0)
		p('a', a, b, f);
	else
	{
		if ((a->rp) <= (a->len - a->rp))
			go_to_top('a', a, b, f);
		else
			go_to_bottom('a', a, b, f);
		p('a', a, b, f);
	}
}
