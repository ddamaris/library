/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:03:16 by exam              #+#    #+#             */
/*   Updated: 2019/11/14 13:38:24 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	is_space(char ch)
{
	if (ch == ' ' || ch == '\t')
		return (1);
	return (0);
}

int	str_len(char *s)
{
	int	l;

	l = 0;
	while (s[l] != '\0')
		l++;
	return (l);
}

int put_str(char *d, char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;

	while (s[i] != '\0')
	{
		while (is_space(s[i]) && s[i] != '\0')
			i++;
		if (!(is_space(s[i])) && s[i] != '\0')
			d[j++] = s[i++];
		if (is_space(s[i]))
			d[j++] = ' ';
	}
	d[j++] = ' ';
	return (j);
}

int	main(int ac, char **av)
{
	int		i;
	int		f;
	int		len;
	char	*s;

	i = 0;
	f = 0;
	if (ac > 1)
	{
		len = str_len(av[1]);
		s = (char *)malloc(sizeof(char) * len + 1);
		len = 0;
		while (is_space(av[1][i]) && av[1][i] != '\0')
			i++;
		f = i;
		while (!(is_space(av[1][i])) && av[1][i] != '\0')
			i++;
		if (av[1][i] != '\0')
			len = put_str(s, &av[1][i]);
		i = 0;
		while (!(is_space(av[1][f + i])) && av[1][f + i] != '\0')
		{
			s[len] = av[1][f + i];
			len++;
			i++;
		}
		s[len] = '\0';
		write(1, s, len);
		free(s);
	}
	write(1, "\n", 1);
	return (0);
}
