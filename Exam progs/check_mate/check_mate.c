// Created by YZU on 23.10.2019.

#include <stdlib.h>
#include <unistd.h>

int		checkmate(int ac, char **av)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	while (i < ac - 1)
	{
		j = 0;
		while (j < ac - 1)
		{
			if (av[i][j] == 'K')
			{
			x = j;
			y = i;
			break;
			}
			j++;
		}
		i++;
	}
	if (av[y + 1][x + 1] == 'P' || av[y + 1][x - 1] == 'P')
		return (0);
	i = 0;
	while (i < ac)
	{
		if (av[y][i] == 'Q' || av[i][x] == 'Q' || av[y][i] == 'R' || av[i][x] == 'R')
			return (0);
		if (i < y)
		{
			if (i < x && (av[y - i - 1][x - i - 1] == 'B' || av[y - i - 1][x - i - 1] == 'Q'))
				return (0);
			if (x + i < ac && (av[y - i - 1][x + i + 1] == 'B' || av[y - i - 1][x+ i + 1] == 'Q'))
				return (0);
		}
		if (y + i < ac)
		{
			if (i < x && (av[y + 1 + i][x - 1 - i] == 'B' || av[y + i + 1][x - 1 - i] == 'Q'))
				return (0);
			if (x + i < ac && (av[y + 1 + i][x + i + 1] == 'B' || av[y + 1 + i][x + i + 1] == 'Q' ))
				return (0);
		}
		i++;
	}
	return (1);
}

int		main(void)
{
	char *av[4] = {"..Q.", "...K", "....", "...."};
	int ac;

	ac = 5;
	if (ac > 1 && !checkmate(ac, av))
		write(1, "Success\n", 8);
	else
		write(1, "Fail\n", 5);
	return (0);
}

