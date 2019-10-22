/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <ddamaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:19:30 by ddamaris          #+#    #+#             */
/*   Updated: 2019/09/09 15:55:07 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*ml;

	ml = (char *)malloc(sizeof(char) * size);
	if (!ml)
		return (NULL);
	ft_bzero(ml, size);
	return (ml);
}
