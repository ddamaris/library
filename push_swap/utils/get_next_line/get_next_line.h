/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <ddamaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:13:47 by ddamaris          #+#    #+#             */
/*   Updated: 2020/02/10 19:33:44 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 5
# define FD_MAX 2

# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		get_next_line(const int fd, char **line);
char	*ft_strchr(const char *s, int c);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strnew(size_t size);
char	*ft_strcpy(char *dst, const char *src);
void	ft_strclr(char *s);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);

#endif
