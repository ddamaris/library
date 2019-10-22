/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:27:28 by ddamaris          #+#    #+#             */
/*   Updated: 2019/09/09 22:41:31 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*d1;
	unsigned char	*d2;

	i = 0;
	d1 = (unsigned char *)s1;
	d2 = (unsigned char *)s2;
	while (d1[i] != '\0')
	{
		if (d2[i] == '\0')
			return (1);
		if (d1[i] != d2[i])
			return (d1[i] - d2[i]);
		i++;
	}
	if (d2[i] != '\0')
		return (-1);
	return (0);
}
