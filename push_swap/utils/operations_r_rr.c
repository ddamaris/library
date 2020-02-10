/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operatios_r_rr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:31:59 by ddamaris          #+#    #+#             */
/*   Updated: 2020/02/05 18:08:26 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	r(char ch, t_stack *a, t_stack *b, t_flags *f)
{
	int		tmp;
	int		i;
	char	*clr;
	t_stack	*st;

	st = (ch == 'a' || ch == 'A') ? a : b;
	if (st->len < 2)
		return ;
	i = -1;
	tmp = st->st[0];
	while (++i < st->len - 1)
		st->st[i] = st->st[i + 1];
	st->st[i] = tmp;
	clr = WHITE;
	if (f->c)
		clr = (ch == 'a') ? CYAN : GREEN;
	if (ch == 'a' || ch == 'b')
	{
		(f->v) ? ft_printf("%s\n--> ", clr) : 0;
		(f->ch) ? ft_printf("r%c\n", ch) : 0;
	}
	if (f->v)
		print_both_stacks(a, b, f);
	if (ch == 'a' || ch == 'b')
		a->opnb++;
}

void	rr(t_stack *a, t_stack *b, t_flags *f)
{
	int		tmp_fl;
	char	*clr;

	clr = WHITE;
	if (f->c)
		clr = MAG;
	(f->v) ? ft_printf("%s\n--> ", clr) : 0;
	(f->ch) ? ft_printf("rr\n") : 0;
	tmp_fl = f->v;
	f->v = 0;
	r('A', a, b, f);
	f->v = (tmp_fl) ? 1 : 0;
	r('B', a, b, f);
	a->opnb++;
}

void	rv(char ch, t_stack *a, t_stack *b, t_flags *f)
{
	int		tmp;
	int		i;
	char	*clr;
	t_stack	*st;

	st = (ch == 'a' || ch == 'A') ? a : b;
	if (st->len < 2)
		return ;
	i = st->len;
	tmp = st->st[st->len - 1];
	while (--i)
		st->st[i] = st->st[i - 1];
	st->st[i] = tmp;
	clr = WHITE;
	if (f->c)
		clr = (ch == 'a') ? CYAN : GREEN;
	if (ch == 'a' || ch == 'b')
	{
		(f->v) ? ft_printf("%s\n--> ", clr) : 0;
		(f->ch) ? ft_printf("rr%c\n", ch) : 0;
	}
	if (f->v)
		print_both_stacks(a, b, f);
	if (ch == 'a' || ch == 'b')
		a->opnb++;
}

void	rrv(t_stack *a, t_stack *b, t_flags *f)
{
	int		tmp_fl;
	char	*clr;

	clr = WHITE;
	if (f->c)
		clr = MAG;
	(f->v) ? ft_printf("%s\n--> ", clr) : 0;
	(f->ch) ? ft_printf("rrr\n") : 0;
	tmp_fl = f->v;
	f->v = 0;
	rv('A', a, b, f);
	f->v = (tmp_fl) ? 1 : 0;
	rv('B', a, b, f);
	a->opnb++;
}
