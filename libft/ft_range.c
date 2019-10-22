/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 19:38:34 by ddamaris          #+#    #+#             */
/*   Updated: 2019/09/04 20:11:17 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int i;
	int l;
	int *r;

	i = 0;
	l = max - min;
	if (l <= 0)
		return (NULL);
	r = (int*)malloc(sizeof(int) * l);
	if (r == NULL)
		return (NULL);
	while (i < l)
	{
		*(r + i) = min + i;
		i++;
	}
	return (r);
}
