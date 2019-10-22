/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:27:50 by ddamaris          #+#    #+#             */
/*   Updated: 2019/09/09 19:23:33 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	while (src[l])
		l++;
	while (i < len)
	{
		if (l > len)
			dst[i] = src[i];
		if (l <= len && i < l)
			dst[i] = src[i];
		if (l <= len && i >= l)
			dst[i] = '\0';
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
