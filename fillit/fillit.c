/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 13:51:22 by ddamaris          #+#    #+#             */
/*   Updated: 2019/10/18 10:09:06 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_exit(void)
{
	ft_putstr("error\n");
	exit(0);
}

int	**make_list(char *bf, int n)
{
	int		i;
	int		**tab;
	char	piece[20];

	i = 0;
	tab = (int **)malloc(sizeof(int *) * n);
	while (*bf)
	{
		ft_strncpy(piece, bf, 20);
		if ((tab[i] = vld_ttrm(piece)))
		{
			bf = bf + 21;
			i++;
		}
		else
			ft_exit();
	}
	return (tab);
}

int	free_list(int **lst, int i)
{
	while (i >= 0)
		free(lst[i--]);
	free(lst);
	return (0);
}

int	main(int ac, char **av)
{
	int		fd;
	int		rd;
	char	buf[BUFF_SIZE];
	int		**tt_list;

	if (ac != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	rd = (int)read(fd, buf, BUFF_SIZE);
	if (fd == -1 || rd <= 0 || ((rd + 1) % 21) != 0 || rd > 545)
		ft_exit();
	else if (!checker(buf))
		ft_exit();
	buf[rd] = '\0';
	tt_list = make_list(buf, (rd + 1) / 21);
	make_map(tt_list, (rd + 1) / 21);
	free_list(tt_list, (rd + 1) / 21 - 1);
	return (0);
}
