/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_s_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:19:19 by ddamaris          #+#    #+#             */
/*   Updated: 2020/02/05 18:01:49 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	s(char ch, t_stack *a, t_stack *b, t_flags *f)
{
	int		tmp;
	char	*clr;
	t_stack	*st;

	st = (ch == 'a' || ch == 'A') ? a : b;
	if (st->len < 2)
		return ;
	tmp = st->st[0];
	st->st[0] = st->st[1];
	st->st[1] = tmp;
	clr = WHITE;
	if (f->c)
		clr = (ch == 'a') ? CYAN : GREEN;
	if (ch == 'a' || ch == 'b')
	{
		(f->v) ? ft_printf("%s\n--> ", clr) : 0;
		(f->ch) ? ft_printf("s%c\n", ch) : 0;
	}
	if (f->v)
		print_both_stacks(a, b, f);
	if (ch == 'a' || ch == 'b')
		a->opnb++;
}

void	ss(t_stack *a, t_stack *b, t_flags *f)
{
	int		tmp_fl;
	char	*clr;

	clr = WHITE;
	if (f->c)
		clr = MAG;
	(f->v) ? ft_printf("%s\n--> ", clr) : 0;
	(f->ch) ? ft_printf("ss\n") : 0;
	tmp_fl = f->v;
	f->v = 0;
	s('A', a, b, f);
	f->v = (tmp_fl) ? 1 : 0;
	s('B', a, b, f);
	a->opnb++;
}

void	p(char ch, t_stack *a, t_stack *b, t_flags *f)
{
	char	*clr;
	int		i;
	t_stack	*sts;
	t_stack	*std;

	std = (ch == 'a') ? a : b;
	sts = (ch == 'a') ? b : a;
	std->len++;
	i = std->len;
	while (--i > 0)
		std->st[i] = std->st[i - 1];
	std->st[0] = sts->st[0];
	i = -1;
	while (++i < sts->len - 1)
		sts->st[i] = sts->st[i + 1];
	sts->len--;
	clr = WHITE;
	if (f->c)
		clr = (ch == 'a') ? CYAN : GREEN;
	(f->v) ? ft_printf("%s\n--> ", clr) : 0;
	(f->ch) ? ft_printf("p%c\n", ch) : 0;
	(f->v) ? print_both_stacks(a, b, f) : 0;
	a->opnb++;
}
