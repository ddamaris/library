/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <ddamaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:34:59 by ddamaris          #+#    #+#             */
/*   Updated: 2019/09/17 20:54:38 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	frln(t_list *str)
{
	t_list	*tmp;

	tmp = str;
	while (str->next)
	{
		tmp = str->next;
		free(str);
		str = tmp;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*nx;
	t_list	*nl;

	if (!lst || !f)
		return (NULL);
	nl = f(lst);
	tmp = nl;
	lst = lst->next;
	while (lst)
	{
		nx = f(lst);
		if (!nx)
			frln(nl);
		tmp->next = nx;
		tmp = nx;
		lst = lst->next;
	}
	tmp->next = NULL;
	return (nl);
}
