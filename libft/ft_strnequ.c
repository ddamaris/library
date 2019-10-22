/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:14:17 by ddamaris          #+#    #+#             */
/*   Updated: 2019/09/13 17:28:41 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t			i;
	unsigned char	*d1;
	unsigned char	*d2;

	i = 0;
	if (s1 && s2)
	{
		d1 = (unsigned char *)s1;
		d2 = (unsigned char *)s2;
		while (d1[i] != '\0' && i < n)
		{
			if (d2[i] == '\0' || d1[i] != d2[i])
				return (0);
			i++;
		}
		if (d2[i] != '\0' && i != n)
			return (0);
		return (1);
	}
	return (0);
}
