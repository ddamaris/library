/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:49:37 by ddamaris          #+#    #+#             */
/*   Updated: 2019/09/12 18:50:36 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	j;
	size_t	i;
	char	*str;
	char	*ns;

	str = (char*)s;
	if (!str)
		return (NULL);
	while (*str == ' ' || *str == '\n' || *str == '\t')
		str++;
	if (*str == '\0')
		return (ns = ft_strnew(0));
	j = ft_strlen(str) - 1;
	while (str[j] == ' ' || str[j] == '\n' || str[j] == '\t')
		j--;
	if (!(ns = ft_strnew(j + 1)))
		return (NULL);
	i = 0;
	while (i <= j)
	{
		ns[i] = str[i];
		i++;
	}
	ns[i] = '\0';
	return (ns);
}
