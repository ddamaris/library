/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:46:21 by ddamaris          #+#    #+#             */
/*   Updated: 2020/02/10 19:49:13 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# define MAG "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"
# define YELLOW "\033[0;33m"
# define GREEN "\033[0;32m"
# define RED "\033[0;31m"

typedef struct	s_stack
{
	int			*st;
	int			min;
	int			i_min;
	int			max;
	int			i_max;
	int			q1;
	int			q2;
	int			q3;
	int			len;
	int			opnb;
	int			rp;
}				t_stack;

typedef struct	s_flags
{
	int			c;
	int			v;
	int			ch;
}				t_flags;
/*
**	Swap two first elements of stack a and stack b
*/
void			s(char ch, t_stack *a, t_stack *b, t_flags *f);
void			ss(t_stack *a, t_stack *b, t_flags *f);
/*
**	Push top element [0]
*/
void			p(char ch, t_stack *a, t_stack *b, t_flags *f);
/*
**	Rotation
*/
void			r(char ch, t_stack *a, t_stack *b, t_flags *f);
void			rr(t_stack *a, t_stack *b, t_flags *f);
/*
**	Revers rotation
*/
void			rv(char ch, t_stack *a, t_stack *b, t_flags *f);
void			rrv(t_stack *a, t_stack *b, t_flags *f);
/*
**	Printing functions
*/
void			print_usage(void);
void			print_stack(char *color, char *st, int *stack, int len);
void			print_both_stacks(t_stack *a, t_stack *b, t_flags *f);
/*
**	Functions
*/
int				check_init(t_stack *a, t_stack *b, int ac, char **av);
int				find_index_of_elem(int el, int *stack, int len);
void			find_min(t_stack *st);
int				find_max(t_stack *st);
void			find_right_place(t_stack *a, int nb);
void			find_right_number(t_stack *a, t_stack *b);
void			search_in_b(t_stack *a, t_stack *b, int min);
int				is_sorted(t_stack *st);
int				parsing(char **argv, t_flags *flags);
int				is_int(char *str);
long			ft_atoi(char *str);
int				check_double(t_stack *a);
void			sort_int(int *tab, int l);
/*
**	PUSH_SWAP
*/
void			stack_sort(t_stack *a, t_stack *b, t_flags *flags);
void			short_sort(t_stack *a, t_stack *b, t_flags *f);
void			long_sort(t_stack *a, t_stack *b, t_flags *f);
void			put_to_right_place(t_stack *a, t_stack *b, t_flags *f);
void			go_to_bottom(char ch, t_stack *a, t_stack *b, t_flags *f);
void			go_both_to_bottom(t_stack *a, t_stack *b, t_flags *f);
void			go_to_top(char ch, t_stack *a, t_stack *b, t_flags *f);
void			go_both_to_top(t_stack *a, t_stack *b, t_flags *f);
void			final_sorting(t_stack *a, t_stack *b, t_flags *f);
/*
**	CHECKER
*/
char			**ft_split(char *str, int *ac);
int				ft_strequ(char const *s1, char const *s2);
void			do_instruction(t_stack *a, t_stack *b, t_flags *f);
int				get_instruction(t_stack *a, t_stack *b, \
					t_flags *f, char *instr);
int				word_length(char *s);
int				words_count(char *str);
int				is_space(char ch);

#endif
