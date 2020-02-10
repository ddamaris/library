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

NAME = g_n_l.a
FLAGS = -Wall -Wextra -Werror
SRCS=	get_next_line.c\
	ft_strnew.c\
	ft_strjoin.c\
	ft_bzero.c\
	ft_strchr.c\
	ft_strlen.c\
	ft_strcpy.c\
	ft_strncat.c\
	ft_strcat.c\
	ft_strdup.c\
	ft_strncmp.c\
	ft_strclr.c\
	ft_strncpy.c

OBJS = $(SRCS:.c=.o)
	
all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	@echo "\033[2K\c"
	@echo "\033[1;34mget_next_line\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"

$(OBJS): $(SRCS)
	gcc $(FLAGS) -c $(SRCS)

clean:
	@rm -rf $(OBJS)
	@echo "\033[1;34mget_next_line\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;34mget_next_line\t\033[1;33mCleaning lib\t\033[0;32m[OK]\033[0m"

re: fclean all

.PHONY: all clean fclean re
