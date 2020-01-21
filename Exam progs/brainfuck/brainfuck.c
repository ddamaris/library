/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:04:57 by exam              #+#    #+#             */
/*   Updated: 2019/11/21 13:22:42 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	go_to_op(char *br, int i)
{
	int	s;

	s = 1;
	while (i && !(br[i] == '[' && s == 0))
	{
		if (br[i] == ']')
			s++;
		if (br[i - 1] == '[')
			s--;
		i--;
	}
	return (i);
}

int	go_to_cl(char *br, int i)
{
	int	s;

	s = 1;
	while (br[i] && !(br[i] == ']' && s == 0))
	{
		if (br[i] == '[')
			s++;
		if (br[i + 1] ==']')
			s--;
		i++;
	}
	return (i);
}

void	brainfuck(char *br, char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (br[i] != '\0')
	{
		if (br[i] == '>')
			j++;
		else if (br[i] == '<')
			j--;
		else if (br[i] == '+')
			s[j]++;
		else if (br[i] == '-')
			s[j]--;
		else if (br[i] == '.')
			write (1, &s[j], 1);
		else if (br[i] == '[' && s[j] == 0)
			i = go_to_cl(br, i + 1);
		else if (br[i] == ']' && s[j] != 0)
			i = go_to_op(br, i - 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i;
	char s[2048];

	i = 0;
	while (i <= 2048)
	{
		s[i] = 0;
		i++;
	}
	s[i] = '\0';
	if (ac < 2)
	{
		write (1, "\n", 1);
		return (0);
	}
	brainfuck(av[1], s);
	return (0);
}
