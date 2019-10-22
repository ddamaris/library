/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <ddamaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:06:52 by ddamaris          #+#    #+#             */
/*   Updated: 2019/09/17 15:34:25 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ns;

	if (s1 && s2)
	{
		ns = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (!ns)
			return (NULL);
		ns = ft_strcpy(ns, s1);
		ns = ft_strcat(ns, s2);
		return (ns);
	}
	return (NULL);
}
