/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moment.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 12:02:47 by exam              #+#    #+#             */
/*   Updated: 2019/10/26 14:26:49 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_len(char *s)
{
	int	i;

	i = 0;
	while(*s)
	{
		i++;
		s++;
	}
	return (i);
}

int		ft_len_n(unsigned int n)
{
	int	l;

	l = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		l++;
	}
	return(l);
}

char	*ft_itoa(char *str, unsigned int d)
{
	int				l;
	unsigned int	n;

	n = d;
	l = ft_len_n(d);
	str[l--] = '\0';
	if (d == 0)
		str[l] = '0';
	while (n != 0)
	{
		str[l--] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

char	*ft_join(unsigned int d, char *s2)
{
	char	*res;
	char	*s1;
	int		i;
	int		l1;
	int		l2;

	i = ft_len_n(d);
	s1 = (char *)malloc(sizeof(char) * i + 1);
	s1 = ft_itoa(s1, d);
	l1 = ft_len(s1);
	l2 = ft_len(s2);
	res = (char *)malloc(sizeof(char) * (l1 + l2) + 1);
	i = -1;
	while (++i < l1)
		res[i] = s1[i];
	i = -1;
	while (++i < l2)
		res[i + l1] = s2[i];
	free(s1);
	return (res);
}

char	*moment(unsigned int duration)
{
	char	*res;

	if (duration == 1)
		res = ft_join(1," second ago");
	else if (duration < 60)
		res = ft_join(duration," seconds ago");
	else if (duration >= 60 && duration < 120)
		res = ft_join(1," minute ago");
	else if (duration >= 120 && duration < 3600)
		res = ft_join(duration / 60," minutes ago");
	else if (duration >= 3600 && duration < 7200)
		res = ft_join(1," hour ago");
	else if (duration >= 7200 && duration < 86400)
		res = ft_join(duration / 3600," hours ago");
	else if (duration >= 86400 && duration < 172800)
		res = ft_join(1," day ago");
	else if (duration >= 172800 && duration < 2592000)
		res = ft_join(duration / 86400," days ago");
	else if (duration >= 2592000 && duration < 5184000)
		res = ft_join(1," month ago");
	else 
		res = ft_join(duration / 2592000," months ago");
	return (res);
}
