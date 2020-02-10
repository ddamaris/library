/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:44:04 by ddamaris          #+#    #+#             */
/*   Updated: 2019/09/10 21:14:52 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*d1;
	unsigned char	*d2;

	i = 0;
	d1 = (unsigned char *)s1;
	d2 = (unsigned char *)s2;
	while (d1[i] != '\0' && i < n)
	{
		if (d2[i] == '\0')
			return (1);
		if (d1[i] != d2[i])
			return (d1[i] - d2[i]);
		i++;
	}
	if (d2[i] != '\0' && i != n)
		return (-1);
	return (0);
}
