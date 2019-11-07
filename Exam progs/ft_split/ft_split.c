/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:02:59 by exam              #+#    #+#             */
/*   Updated: 2019/11/07 13:59:49 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int is_space(char ch)
{
	if (ch == ' ' || ch == '\n' || ch == '\t')
		return (1);
	return (0);
}

int		words_count(char *str)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (str[i] != '\0')
	{
		while (is_space(str[i]))
			i++;
		if (!is_space(str[i]) && str[i] != '\0')
			wc++;
		while (!is_space(str[i]) && str[i] != '\0')
			i++;
	}
	return (wc);
}

int	word_length(char *s)
{
	int	l;

	l = 0;
	while (!is_space(s[l]) && s[l] != '\0')
		l++;
	return (l);
}

char	**ft_split(char *str)
{
	char	**tab;
	int		nw;
	int		i;
	int		j;
	int		lw;

	i = 0;
	j = -1;
	tab = (char **)malloc(sizeof(char *) * ((nw = words_count(str)) + 1));
	tab[nw] = NULL;
	while (++j < nw)
	{
		lw = 0;
		while (is_space(str[i]))
			i++;
		lw = (str[i] != '\0') ? word_length(&str[i]) : 0;
		tab[j] = (char *)malloc(sizeof(char) * (lw + 1));
		tab[j][lw] = '\0';
		while (--lw >= 0)
			tab[j][lw] = str[i + lw];
		while (!is_space(str[i]) && str[i] != '\0')
			i++;
	}
	return (tab);
}
