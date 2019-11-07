/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensch <fwuensch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 10:05:56 by exam              #+#    #+#             */
/*   Updated: 2019/03/14 14:02:53 by fwuensch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		go_to_cl(char *op, int i)
{
	int s;

	s = 0;
	while (!(op[i] == ']' && s == 0))
	{
		if (op[i] == '[')
			s++;
		else if (op[i] == ']')
			s--;
		i++;
	}
	i--;
	return (i);
}

int		go_to_op(char *op, int i)
{
	int s;

	s = 0;
	while (!(op[i] == '[' && s == 0))
	{
		if (op[i] == ']')
			s++;
		else if (op[i] == '[')
			s--;
		i--;
	}
	i--;
	return (i);
}

void	brain_fuck(char *op, char *d)
{
	int i = 0;
	int j = 0;

	while (op[i])
	{
		if (op[i] == '>')
			j++;
		else if (op[i] == '<')
			j--;
		else if (op[i] == '+')
			d[j]++;
		else if (op[i] == '-')
			d[j]--;
		else if (op[i] == '.')
			write(1, &d[j], 1);
		else if (op[i] == '[' && d[j] == 0)
			i = go_to_cl(op, i + 1);
		else if (op[i] == ']' && d[j] != 0)
			i = go_to_op(op, i - 1);
		i++;
	}
}

int		main(void)
{
	char *av = "+++++[>++++[>++++H>+++++i<<-]>>>++\n<<<<-]>>--------.>+++++.>.";
	char d[2048];
	int i;

	i = 0;
	while (i < 2048)
		d[i++] = 0;
	d[i] = '\0';
	brain_fuck(av, d);
	write(1, "\n", 1);
	return (0);
}
