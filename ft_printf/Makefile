
GCC = gcc

F = -Wall -Wextra -Werror

NAME = libftprintf.a

OBJECT = ./ft_printf.o \
	./parse.o \
	./parse_continue.o \
	./parse_format.o \
	./handle_s.o \
	./handle_c.o \
	./handle_percent.o \
	./handle_d.o \
	./handle_u.o \
	./handle_x.o \
	./handle_o.o \
	./handle_p.o \
	./handle_f.o \
	./handle_f_continue.o \
	./handle_f_more.o \

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECT)
		ar rc $(NAME) $(OBJECT)
		ranlib $(NAME)

clean:
	rm -rf $(OBJECT)

fclean: clean
	rm -rf $(NAME)

re: fclean all

ft_printf.o: ft_printf.c
	$(GCC) $(F) -c ft_printf.c

parse.o: parse.c
	$(GCC) $(F) -c parse.c

parse_continue.o: parse_continue.c
	$(GCC) $(F) -c parse_continue.c

parse_format.o: parse_format.c
	$(GCC) $(F) -c parse_format.c

handle_s.o: handle_s.c
	$(GCC) $(F) -c handle_s.c

handle_c.o: handle_c.c
	$(GCC) $(F) -c handle_c.c

handle_percent.o: handle_percent.c
	$(GCC) $(F) -c handle_percent.c

handle_d.o: handle_d.c
	$(GCC) $(F) -c handle_d.c

handle_u.o: handle_u.c
	$(GCC) $(F) -c handle_u.c

handle_x.o: handle_x.c
	$(GCC) $(F) -c handle_x.c

handle_o.o: handle_o.c
	$(GCC) $(F) -c handle_o.c

handle_p.o: handle_p.c
	$(GCC) $(F) -c handle_p.c

handle_f.o: handle_f.c
	$(GCC) $(F) -c handle_f.c

handle_f_continue.o: handle_f_continue.c
	$(GCC) $(F) -c handle_f_continue.c

handle_f_more.o: handle_f_more.c
	$(GCC) $(F) -c handle_f_more.c