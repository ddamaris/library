/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <ddamaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 23:15:45 by ddamaris          #+#    #+#             */
/*   Updated: 2019/09/16 17:03:19 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nl(long n)
{
	int	i;

	i = 0;
	if (n == 0 || n < 0)
		i = 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	fill(char *s, long n, int i)
{
	int		ch;
	char	*str;

	str = s;
	while (i >= 0)
	{
		ch = n % 10;
		n = n / 10;
		str[i] = ch + '0';
		i--;
	}
}

char		*ft_itoa(int n)
{
	int		i;
	int		s;
	long	nb;
	char	*ns;

	nb = (long)n;
	i = nl(nb);
	s = 1;
	if (n < 0)
		s = -1;
	ns = (char *)malloc(sizeof(char) * (i + 1));
	if (!ns)
		return (NULL);
	ns[i--] = '\0';
	nb = nb * s;
	fill(ns, nb, i);
	if (s < 0)
		ns[0] = '-';
	return (ns);
}
