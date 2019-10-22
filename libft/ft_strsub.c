/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:22:31 by ddamaris          #+#    #+#             */
/*   Updated: 2019/09/12 18:55:26 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ns;

	ns = NULL;
	i = 0;
	if (s)
	{
		i = ft_strlen(s);
		if (start <= i && (start + len) <= i)
		{
			ns = (char *)malloc(sizeof(char) * len + 1);
			if (!ns)
				return (NULL);
			i = 0;
			while (i < len)
			{
				ns[i] = s[i + start];
				i++;
			}
			ns[i] = '\0';
			return (ns);
		}
	}
	return (NULL);
}
