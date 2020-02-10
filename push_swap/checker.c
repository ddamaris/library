/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:20:56 by ddamaris          #+#    #+#             */
/*   Updated: 2020/02/05 17:25:27 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils/utils.h"

int		get_instruction(t_stack *a, t_stack *b, t_flags *f, char *instr)
{
	if (ft_strequ(instr, "sa"))
		s('a', a, b, f);
	else if (ft_strequ(instr, "sb"))
		s('b', a, b, f);
	else if (ft_strequ(instr, "ss"))
		ss(a, b, f);
	else if (ft_strequ(instr, "pa"))
		p('a', a, b, f);
	else if (ft_strequ(instr, "pb"))
		p('b', a, b, f);
	else if (ft_strequ(instr, "ra"))
		r('a', a, b, f);
	else if (ft_strequ(instr, "rb"))
		r('b', a, b, f);
	else if (ft_strequ(instr, "rr"))
		rr(a, b, f);
	else if (ft_strequ(instr, "rra"))
		rv('a', a, b, f);
	else if (ft_strequ(instr, "rrb"))
		rv('b', a, b, f);
	else if (ft_strequ(instr, "rrr"))
		rrv(a, b, f);
	else
		return (1);
	return (0);
}

void	do_instruction(t_stack *a, t_stack *b, t_flags *f)
{
	char	*instr;
	int		er;

	while ((a->min = get_next_line(0, &instr)) >= 0)
	{
		if (!instr || instr[0] == '\0')
			break ;
		er = get_instruction(a, b, f, instr);
		if (er == 1)
		{
			ft_printf("Error\n");
			free(instr);
			exit(1);
		}
		free(instr);
		instr = NULL;
	}
	free(instr);
}

int		main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	t_flags	flags;

	if (ac < 2)
		exit(0);
	if (!(av[1][0] == '-' && (av[1][1] >= '0' && av[1][1] <= '9')) &&
		!(av[1][0] >= '0' && av[1][0] <= '9'))
		return (ft_printf("Error\n"));
	if (!(check_init(&a, &b, ac, av)))
		return (0);
	flags.v = 0;
	flags.ch = (flags.v) ? 1 : 0;
	do_instruction(&a, &b, &flags);
	if (is_sorted(&a) && a.i_min == 0 && b.len == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(a.st);
	free(b.st);
	return (0);
}
