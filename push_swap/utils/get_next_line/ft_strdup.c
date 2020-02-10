/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:38:13 by ddamaris          #+#    #+#             */
/*   Updated: 2019/09/09 15:41:51 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	size_t	l;
	size_t	i;
	char	*dup;

	i = 0;
	while (s1[i])
		i++;
	l = i;
	i = 0;
	dup = (char *)malloc(sizeof(char) * l + 1);
	if (!dup)
		return (NULL);
	while (i <= l)
	{
		dup[i] = s1[i];
		i++;
	}
	return (dup);
}
