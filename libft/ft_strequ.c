/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:58:42 by ddamaris          #+#    #+#             */
/*   Updated: 2019/09/11 22:05:01 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	size_t			i;
	unsigned char	*d1;
	unsigned char	*d2;

	if (s1 && s2)
	{
		i = 0;
		d1 = (unsigned char *)s1;
		d2 = (unsigned char *)s2;
		while (d1[i])
		{
			if (d2[i] == '\0' || d1[i] != d2[i])
				return (0);
			i++;
		}
		if (d2[i] != '\0')
			return (0);
		return (1);
	}
	return (0);
}
