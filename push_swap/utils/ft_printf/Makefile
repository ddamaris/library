NAME = ft_printf.a
FLAGS = -Wall -Wextra -Werror
SRCS =  ft_bzero.c\
	ft_is_flag.c\
	ft_printf.c\
	ft_strlen.c\
	ft_strnew.c\
	ft_work_out.c\
	str_longmath.c\
	long_math.c\
	work_out_char.c\
	work_out_d.c\
	work_out_f.c\
	work_out_uxo.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	@echo "\033[2K\c"
	@echo "\033[1;34mft_printf\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"

$(OBJS): $(SRCS)
	gcc $(FLAGS) -c $(SRCS)

clean:
	@rm -rf $(OBJS)
	@echo "\033[1;34mft_printf\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;34mft_printf\t\033[1;33mCleaning lib\t\033[0;32m[OK]\033[0m"

re: fclean all

.PHONY: all clean fclean re
