/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:26:08 by ddamaris          #+#    #+#             */
/*   Updated: 2020/02/05 17:45:28 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s2[i] == '\0')
			return (0);
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s2[i] != '\0')
		return (0);
	return (1);
}

int		is_space(char ch)
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

int		word_length(char *s)
{
	int	l;

	l = 0;
	while (!is_space(s[l]) && s[l] != '\0')
		l++;
	return (l);
}

char	**ft_split(char *str, int *ac)
{
	char	**tab;
	int		nw;
	int		i;
	int		j;
	int		lw;

	i = 0;
	j = -1;
	nw = words_count(str);
	tab = (char **)malloc(sizeof(char *) * (nw + 1));
	tab[nw] = NULL;
	while (++j < nw)
	{
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
	*ac = nw + 1;
	return (tab);
}
