/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:43:44 by exam              #+#    #+#             */
/*   Updated: 2019/10/31 15:38:48 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "options.h"

int		check_param(char *s)
{
	int	i;

	i = 1;
	if (s[0] != '-')
		return (2);
	while (s[i] != '\0')
	{
		if (s[i] < 'a' || s[i] > 'z')
		{
			write(1, "Invalid Option\n", 15);
			return (0);
		}
		if (s[i] == 'h')
		{
			write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
			return (0);
		}
		else
		   i++;
	}
	return (1);
}

void	fill_str(char *pr, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (pr[j] != '\0')
	{
		i = 31 - (pr[j] - 'a');
		str[i] = '1';
		j++;
	}
}

void	print_str(char *str)
{
	write(1, &str[0], 8);
	write(1, " ", 1);
	write(1, &str[8], 8);
	write(1, " ", 1);
	write(1, &str[16], 8);
	write(1, " ", 1);
	write(1, &str[24], 8);
	write(1, "\n", 1);
}

int		main(int ac, char **av)
{
	int	i;
	char s[32];

	i = 0;
	while (i < 32)
		s[i++] = '0';
	if (ac == 1)
	{
		write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
		return (0);
	}
	i = 1;
	while (i < ac)
	{
		if (check_param(av[i]) == 0)
			return (0);
		else if (check_param(av[i]) == 1)
			fill_str(av[i], s);	
		i++;
	}
	print_str(s);
	return (0);
}
