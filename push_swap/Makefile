# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/28 17:49:37 by ddamaris          #+#    #+#              #
#    Updated: 2020/01/28 17:49:54 by ddamaris         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap
CHECKER = checker
FLAGS = -Wall -Wextra -Werror

SRCS1 = push_swap.c
SRCS2 = checker.c

OBJS = $(SRCS:.c=.o)

INCL1 = utils/ft_printf/ft_printf.a utils/*.c
INCLUDES = utils/ft_printf/ft_printf.a utils/get_next_line/g_n_l.a utils/*.c

all: $(NAME)
	@make -C utils/ft_printf/ all
	@make -C utils/get_next_line/ all
	gcc -o $(PUSH_SWAP) $(FLAGS) $(SRCS1) $(INCLUDES)
	gcc -o $(CHECKER) $(FLAGS) $(SRCS2) $(INCLUDES)
	
clean:
	@make -C utils/ft_printf clean
	@make -C utils/get_next_line clean

fclean: clean
	/bin/rm -f $(CHECKER)
	/bin/rm -f $(PUSH_SWAP)
	@make -C utils/ft_printf/ fclean
	@make -C utils/get_next_line/ fclean

re: fclean all

push_swap:
	@make -C utils/ft_printf/ all
	gcc -o $(PUSH_SWAP) $(FLAGS) $(SRCS1) $(INCL1)

checker:
	@make -C utils/ft_printf/ all
	@make -C utils/get_next_line/ all
	gcc -o $(CHECKER) $(FLAGS) $(SRCS2) $(INCLUDES)

.PHONY: all clean fclean re
