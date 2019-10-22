/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <ddamaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 19:20:32 by ddamaris          #+#    #+#             */
/*   Updated: 2019/09/09 13:31:49 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ms;
	unsigned char	cc;

	i = 0;
	ms = (unsigned char *)b;
	cc = (unsigned char)c;
	while (i < len)
	{
		ms[i] = cc;
		i++;
	}
	return (ms);
}
