// Created by YZU on 22.10.2019.

#include "flood_fill.h"
#include <stdio.h>
#include <stdlib.h>

char** make_area(char **a, t_point size)
{
	char **res;
	int  i, j;
	res = (char **) malloc(sizeof(char *) * (size.y - 1));
	i = 0;
	while (i < size.y)
	{
		res[i] = malloc(sizeof(char *) * size.x);
		j = 0;
		while (j < size.x)
		{
			res[i][j] = a[i][j];
			j++;
		}
		res[i][j] = '\0';
		i++;
	}
	return (res);
}

void	print_tab(char **a, t_point size)
{
	int i;
	int j;

	i = 0;
	while (i < size.y)
	{
		j = 0;
		while (j < size.x)
		{
			printf("%c ", a[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}

void	flood_fill(char **tab, t_point size, t_point begin) {
	int i;
	char c;

	i = 0;
	c = tab[begin.y][begin.x];
	tab[begin.y][begin.x] = 'F';
	print_tab(tab, size);
	printf("\n");
	if (begin.y > 0 && tab[begin.y - 1][begin.x] == c) {
		begin.y -= 1;
		flood_fill(tab, size, begin);
	}
	if (begin.y < size.y && tab[begin.y + 1][begin.x] == c) {
		begin.y += 1;
		flood_fill(tab, size, begin);
	}
	if (begin.x > 0 && tab[begin.y][begin.x - 1] == c) {
		begin.x -= 1;
		flood_fill(tab, size, begin);
	}
	if (begin.x < size.x && tab[begin.y][begin.x + 1] == c) {
		begin.x += 1;
		flood_fill(tab, size, begin);
	}
}

int main(void)
{
	t_point size = {8, 5};
	t_point begin = {2, 2};
	char **area;
	char *zone[] = {
			"11111111",
			"10001001",
			"10010001",
			"10110001",
			"11100001",
	};
	area = make_area((char **) zone, size);
//	print_tab(area, size);
	flood_fill(area, size, begin);
	printf("\n");
	print_tab(area, size);
	return (0);
}
