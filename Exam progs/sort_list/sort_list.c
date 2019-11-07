/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:03:41 by exam              #+#    #+#             */
/*   Updated: 2019/10/31 12:36:13 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int,int))
{
	t_list	*bgn;
	t_list	*tmp;
	int		b;

	bgn = lst;
	while (lst)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (!(cmp(lst->data, tmp->data)))
			{
				b = tmp->data;
				tmp->data = lst->data;
				lst->data = b;
			}
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (bgn);
}
