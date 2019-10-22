/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <ddamaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:46:06 by ddamaris          #+#    #+#             */
/*   Updated: 2019/09/17 13:54:20 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*nl;

	if (!(nl = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		nl->content = NULL;
		nl->content_size = 0;
	}
	else
	{
		if (!(nl->content = malloc(content_size)))
		{
			free(nl);
			return (NULL);
		}
		ft_memcpy(nl->content, content, content_size);
		nl->content_size = content_size;
	}
	nl->next = NULL;
	return (nl);
}
