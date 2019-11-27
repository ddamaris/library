cmake_minimum_required(VERSION 3.15)
project(ft_printf C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ft_printf
		ft_printf.c
		ft_printf.h
		handle_c.c
		handle_d.c
		handle_f.c
		handle_f_continue.c
		handle_f_more.c
		handle_o.c
		handle_p.c
		handle_percent.c
		handle_s.c
		handle_u.c
		handle_x.c
		main.c
		parse.c
		parse_continue.c
		parse_format.c
		print_char.c)
