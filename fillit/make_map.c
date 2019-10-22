/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:13:15 by ddamaris          #+#    #+#             */
/*   Updated: 2019/10/18 11:20:42 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	put_ttrm(char *map, int *ttrm, int ms, char ch)
{
	int		t2;
	int		t3;
	int		t4;

	t2 = ttrm[0] * (ms + 1) + ttrm[1];
	t3 = ttrm[2] * (ms + 1) + ttrm[3];
	t4 = ttrm[4] * (ms + 1) + ttrm[5];
	map[0] = ch;
	map[t2] = ch;
	map[t3] = ch;
	map[t4] = ch;
}

char	*map_init(int ms)
{
	char	*tmp;
	int		i;
	int		sz;

	sz = ms * (ms + 1);
	tmp = (char *)malloc(sizeof(char) * (sz + 1));
	if (!tmp)
		ft_exit();
	i = 0;
	while (i < sz)
	{
		if ((i + 1) % (ms + 1) == 0)
			tmp[i] = '\n';
		else
			tmp[i] = '.';
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int		right_place(char *map, int *ttrm, int ms)
{
	int		t2;
	int		t3;
	int		t4;

	t2 = ttrm[0] * (ms + 1) + ttrm[1];
	t3 = ttrm[2] * (ms + 1) + ttrm[3];
	t4 = ttrm[4] * (ms + 1) + ttrm[5];
	if (map[0] == '\n' || map[t2] == '\n' || map[t3] == '\n' || map[t4] == '\n')
		return (0);
	else if
		(map[0] != '.' || map[t2] != '.' || map[t3] != '.' || map[t4] != '.')
		return (0);
	return (1);
}

int		draw_map(int **lst, char *map, int nb, int i)
{
	int		x;
	char	ch;
	int		ms;

	x = 0;
	ms = map_size(map);
	ch = 'A' + i;
	if (i < nb)
	{
		while ((x + lst[i][4] * (ms + 1) + lst[i][5]) < ms * (ms + 1))
		{
			if (right_place(&map[x], lst[i], ms))
			{
				put_ttrm(&map[x], lst[i], ms, ch);
				if ((draw_map(lst, map, nb, i + 1)))
					return (1);
				else
					put_ttrm(&map[x], lst[i], ms, '.');
			}
			x++;
		}
		return (0);
	}
	return (1);
}

int		make_map(int **tt_list, int nb)
{
	int		i;
	int		ms;
	char	*map;

	i = 0;
	while (i * i < nb * 4)
		i++;
	ms = i;
	map = map_init(ms);
	while (!(draw_map(tt_list, map, nb, 0)))
	{
		free(map);
		ms++;
		map = map_init(ms);
	}
	ft_putstr(map);
	return (0);
}
