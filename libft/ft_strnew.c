/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <ddamaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:17:31 by ddamaris          #+#    #+#             */
/*   Updated: 2019/09/17 13:22:18 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*sn;

	if (size + 1 == 0)
		return (NULL);
	sn = (char *)malloc(sizeof(char) * size + 1);
	if (sn)
		ft_bzero(sn, size + 1);
	return (sn);
}
