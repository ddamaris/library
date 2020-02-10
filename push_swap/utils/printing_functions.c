/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:17:49 by ddamaris          #+#    #+#             */
/*   Updated: 2020/01/25 16:19:04 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_usage(void)
{
	ft_printf("usage: push_swap [ -v -c ] [integer numbers...]\n");
	ft_printf("options:\n-v visualise\n-c colored visualisation");
}

void	print_stack(char *color, char *st, int *stack, int len)
{
	int	i;

	i = -1;
	ft_printf("%s%s [", color, st);
	while (++i < len - 1)
		ft_printf(" %d,", stack[i]);
	ft_printf(" %d ]\n", stack[i]);
}

void	print_both_stacks(t_stack *a, t_stack *b, t_flags *f)
{
	char	*clr;

	clr = WHITE;
	if (f->c)
		clr = CYAN;
	if (a->len)
		print_stack(clr, "Stack A:", a->st, a->len);
	else
		ft_printf("%sStack A: [ ]\n", clr);
	if (f->c)
		clr = GREEN;
	if (b->len)
		print_stack(clr, "Stack B:", b->st, b->len);
	else
		ft_printf("%sStack B: [ ]\n", clr);
}
