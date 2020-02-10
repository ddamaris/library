/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:54:23 by ddamaris          #+#    #+#             */
/*   Updated: 2020/02/05 17:33:37 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils/utils.h"

void	stack_sort(t_stack *a, t_stack *b, t_flags *flags)
{
	char	*clr;

	if (flags->v)
	{
		clr = (flags->c) ? YELLOW : WHITE;
		print_stack(clr, "Input array:", a->st, a->len);
	}
	if (!(is_sorted(a) && b->len == 0))
	{
		if (a->len < 6)
			short_sort(a, b, flags);
		else
			long_sort(a, b, flags);
	}
	final_sorting(a, b, flags);
	if (flags->v)
	{
		clr = (flags->c) ? YELLOW : WHITE;
		print_stack(clr, "\nSorted array:", a->st, a->len);
		if (a->opnb)
		{
			clr = (flags->c) ? RED : WHITE;
			ft_printf("%sNumber of operations = %d\n", clr, a->opnb);
		}
	}
}

int		main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	t_flags	flags;

	if (ac < 2)
		return (0);
	if (ac == 2 && av++)
	{
		av = ft_split(av[0], &ac);
		av--;
	}
	flags.ch = 1;
	if (!(parsing(av, &flags)))
		return (0);
	if (!(check_init(&a, &b, ac, av)))
		return (0);
	stack_sort(&a, &b, &flags);
	free(a.st);
	free(b.st);
	return (0);
}
