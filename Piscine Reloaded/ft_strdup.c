/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:39:34 by ddamaris          #+#    #+#             */
/*   Updated: 2019/09/04 19:30:30 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*pd;

	i = 0;
	while (src[i])
		i++;
	pd = (char*)malloc(sizeof(char) * i + 1);
	i = 0;
	while (src[i])
	{
		*(pd + i) = src[i];
		i++;
	}
	*(pd + i) = '\0';
	return (pd);
}
