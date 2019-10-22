/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:51:47 by ddamaris          #+#    #+#             */
/*   Updated: 2019/09/11 19:58:06 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ns;

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
			ns[i] = f(i, s[i]);
			i++;
		}
		ns[i] = '\0';
		return (ns);
	}
	return (NULL);
}
