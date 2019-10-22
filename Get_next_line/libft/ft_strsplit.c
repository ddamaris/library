/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:51:20 by ddamaris          #+#    #+#             */
/*   Updated: 2019/09/16 17:02:30 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		w_c(char const *s, char ch)
{
	int		i;
	int		cnt;

	i = 0;
	if (!*s)
		return (0);
	cnt = 0;
	if (s[i++] != ch)
		cnt = 1;
	while (s[i])
	{
		if (s[i - 1] == ch && s[i] != ch)
			cnt++;
		i++;
	}
	return (cnt);
}

static size_t	w_l(char const *s, char ch)
{
	int		l;

	l = 0;
	while (s[l] != ch && s[l])
		l++;
	return (l);
}

static char		**t_cln(char **tab, int l)
{
	int		i;

	i = 0;
	while (i < l)
	{
		free(tab[i++]);
		tab[i] = NULL;
	}
	free(tab);
	tab = NULL;
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		wc;

	if (!s)
		return (NULL);
	j = 0;
	i = 0;
	wc = w_c(s, c);
	if (!(tab = (char **)malloc(sizeof(char*) * (wc + 1))))
		return (NULL);
	while (j < wc)
	{
		while (s[i] && s[i] == c)
			i++;
		tab[j] = ft_strsub(s, i, w_l(&s[i], c));
		if (!tab[j])
			return (t_cln(tab, j));
		while (s[i] && s[i] != c)
			i++;
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
