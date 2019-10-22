# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frenna <frenna@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 22:20:11 by ddamaris          #+#    #+#              #
#    Updated: 2019/10/18 11:56:40 by frenna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

GCCFLAGS = -Wall -Wextra -Werror

SRCS= ft_bzero.c ft_putchar.c ft_putstr.c ft_strncat.c ft_strchr.c \
			ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strjoin.c \
			ft_strlen.c ft_strcat.c ft_strncmp.c ft_strncpy.c ft_strnew.c

OBJ=$(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rv $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ):
	gcc  $(GCCFLAGS) -c $(SRCS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all