/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:58:46 by ddamaris          #+#    #+#             */
/*   Updated: 2019/09/09 17:52:47 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlen_k(const char *s)
{
	size_t	i;
	int		res;

	res = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] <= 31 && s[i] > 0)
			res += 3;
		else
			res++;
		i++;
	}
	return (res);
}
