# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddamaris <ddamaris@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 22:20:11 by ddamaris          #+#    #+#              #
#    Updated: 2019/09/17 13:05:22 by ddamaris         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCCFLAGS = -Wall -Wextra -Werror

SRCS=	get_next_line.c\
	ft_strnew.c\
	ft_strjoin.c\
	ft_bzero.c\
	ft_strchr.c\
	ft_strlen.c\
	ft_strcmp.c\
	ft_strcpy.c\
	ft_strncat.c\
	ft_strcat.c\
	ft_strdup.c\
	ft_strncmp.c\
	ft_strclr.c\
	ft_strncpy.c

norm:
	norminette -R CheckForbiddenSourceHeader $(SRCS)	
all:
	gcc $(GCCFLAGS) $(SRCS)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all