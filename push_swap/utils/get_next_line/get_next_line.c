/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <ddamaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:10:49 by ddamaris          #+#    #+#             */
/*   Updated: 2020/02/05 18:54:08 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_cpy(char *s1, char *s2)
{
	char	*tmp;

	if (!s1 || (!s1[0] && s2[0]))
	{
		tmp = ft_strnew(ft_strlen(s2));
		if (!tmp)
			return (NULL);
		tmp = ft_strcpy(tmp, s2);
	}
	else
	{
		tmp = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (!tmp)
			return (NULL);
		tmp = ft_strcpy(tmp, s1);
		tmp = ft_strcat(tmp, s2);
	}
	free(s1);
	return (tmp);
}

char	*check_last(char **rem, char **line)
{
	char	*pn;

	pn = NULL;
	*line = ft_strnew(1);
	if (*rem)
		if ((pn = ft_strchr(*rem, '\n')))
		{
			*pn = '\0';
			*line = new_cpy(*line, *rem);
			ft_strcpy(*rem, ++pn);
		}
		else
		{
			*line = new_cpy(*line, *rem);
			ft_strclr(*rem);
		}
	else
		*rem = ft_strnew(1);
	return (pn);
}

int		get_next_line(const int fd, char **line)
{
	static char	*tab[FD_MAX];
	int			rd;
	char		*pn;
	char		buf[BUFF_SIZE + 1];

	if (!line || fd < 0 || fd > FD_MAX)
		return (-1);
	rd = 1;
	pn = check_last(&tab[fd], line);
	while (!pn && (rd = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rd] = '\0';
		if ((pn = ft_strchr(buf, '\n')))
		{
			*(pn++) = '\0';
			tab[fd] = new_cpy(tab[fd], pn);
		}
		*line = new_cpy(*line, buf);
	}
	if (rd < 0)
		return (-1);
	return ((rd > 0) ? 1 : 0);
}
