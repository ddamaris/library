/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:34:18 by ddamaris          #+#    #+#             */
/*   Updated: 2019/09/11 19:50:46 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*ns;

	i = 0;
	ns = NULL;
	if (s && f)
	{
		while (s[i])
			i++;
		ns = (char *)malloc(sizeof(char) * i + 1);
		if (!ns)
			return (NULL);
		i = 0;
		while (s[i])
		{
			ns[i] = f(s[i]);
			i++;
		}
		ns[i] = '\0';
		return (ns);
	}
	return (NULL);
}
