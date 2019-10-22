/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 20:30:44 by ddamaris          #+#    #+#             */
/*   Updated: 2019/09/09 17:52:17 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	cc;
	unsigned char	*d;

	i = 0;
	d = (unsigned char *)s;
	cc = (unsigned char)c;
	while (i < n)
	{
		if (d[i] == cc)
			return (&d[i]);
		i++;
	}
	return (NULL);
}
