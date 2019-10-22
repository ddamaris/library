/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:03:43 by ddamaris          #+#    #+#             */
/*   Updated: 2019/09/09 23:44:28 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	l;

	i = 0;
	l = ft_strlen(s2);
	if (!*s2)
		return ((char *)s1);
	while (s1[i])
	{
		if (!ft_memcmp(&s1[i], s2, l))
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}
