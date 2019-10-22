/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vld_ttrm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:36:09 by ddamaris          #+#    #+#             */
/*   Updated: 2019/10/18 10:39:10 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int g_vld[19][6] = {{1, 0, 2, 0, 3, 0}, {0, 1, 0, 2, 0, 3},
	{0, 1, 0, 2, 1, 2}, {1, 0, 2, -1, 2, 0}, {1, 0, 1, 1, 1, 2},
	{0, 1, 1, 0, 2, 0}, {0, 1, 0, 2, 1, 1}, {1, -1, 1, 0, 2, 0},
	{1, -1, 1, 0, 1, 1}, {1, 0, 1, 1, 2, 0}, {0, 1, 0, 2, 1, 0},
	{0, 1, 1, 1, 2, 1}, {1, -2, 1, -1, 1, 0}, {1, 0, 2, 0, 2, 1},
	{0, 1, 1, -1, 1, 0}, {1, 0, 1, 1, 2, 1}, {0, 1, 1, 1, 1, 2},
	{1, -1, 1, 0, 2, -1}, {0, 1, 1, 0, 1, 1}};

int		map_size(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\n')
		i++;
	return (i);
}

int		*ft_strintdup(int *s1, int n)
{
	int	*dup;
	int	i;

	i = 0;
	dup = (int *)malloc(sizeof(int) * n);
	if (!dup)
		return (NULL);
	while (i < n)
	{
		dup[i] = s1[i];
		i++;
	}
	return (dup);
}

int		*vld_ttrm(char *s)
{
	int i;

	i = 0;
	while (*s != '#')
		s++;
	while (i < 19)
	{
		if (*s == '#' && *(s + g_vld[i][0] * 5 + g_vld[i][1]) == '#' &&
			*(s + g_vld[i][2] * 5 + g_vld[i][3]) == '#' &&
			*(s + g_vld[i][4] * 5 + g_vld[i][5]) == '#')
			return (ft_strintdup(g_vld[i], 6));
		i++;
	}
	return (NULL);
}

int		checker(char *bf)
{
	int	i;
	int	n;
	int d;
	int h;

	while (*bf != '\0')
	{
		i = 0;
		n = 0;
		d = 0;
		h = 0;
		while (i < 20)
		{
			h += (bf[i] == '#') ? 1 : 0;
			d += (bf[i] == '.') ? 1 : 0;
			n += (bf[i++] == '\n') ? 1 : 0;
		}
		if (!(n == 4 && h == 4 && d == 12) ||
			!(bf[i] == '\n' || bf[i] == '\0'))
			return (0);
		bf = bf + 21;
	}
	return (1);
}
