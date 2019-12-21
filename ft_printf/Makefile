NAME = ft_printf
FLAGS = -Wall -Wextra -Werror
SRCS =  ft_is_flag.c ft_printf.c ft_work_out.c work_out_char.c work_out_d.c work_out_uxo.c ft_strlen.c
LIB = libftprintf.a
OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(LIB)
	gcc $(FLAGS) $(LIB) main.c -o $(NAME)

$(LIB): $(OBJS)
	ar rc $(LIB) $(OBJS)
	ranlib $(LIB)
	@echo "\033[2K\c"
	@echo "\033[1;34mft_printf\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"

%.o:%.c
	gcc $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS) $(LIB)
	@echo "\033[1;34mft_printf\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;34mft_printf\t\033[1;33mCleaning lib\t\033[0;32m[OK]\033[0m"

re: fclean all

.PHONY: all clean fclean re