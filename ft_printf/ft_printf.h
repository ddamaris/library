
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define ABS(x) ((x < 0) ? -(x) : (x))

typedef	struct		s_struct
{
	char			plus;
	char			minus;
	char			hash;
	char			zero;
	char			morezero;
	char			blank;
	int				width;
	int				prec;
	char			hh;
	char			h;
	char			ll;
	char			l;
	char			z;
	char			j;
	char			spec;
	short			size;
	int				len;
	int				largel;
	int				res;
}					t_struct;

typedef struct		s_float
{
	long long int	length;
	long long int	length2;
	long long int	number;
	long double		number4;
	long long int	i;
	long long int	position;
	long long int	sign;
	long double		number2;
	long double		number3;
	long double		f;
	char			*r;
	char			*str;
	int				len;
	int				p;
	int				k;
}					t_float;

int					ft_out(t_struct *list, va_list va);
int					ft_handling_digit(t_struct *list, void *digit);
int					ft_handling_str(t_struct *list, void *str);
int					ft_print_str(char *str, int precision);
int					ft_strlen(const char *s);
int					ft_handling_char(t_struct *list, void *c);
int					ft_print_percent(t_struct *list, char c);
int					ft_print_char(char c);
int					check_one(t_float *f_nums);
int					print_char(const char *format, int i);
int					ft_printf(const char *format, ...);
int					pa(const char *format, int i, va_list va, t_struct *list);
void				define_list(t_struct *list);
void				found_flags(const char *format, int i, t_struct *list);
void				parse_format_c(const char *format, int i, t_struct *list);
void				innitiaize_struct_float(t_float *f_nums);
void				float_tenth_len(t_float *f_nums);
void				float_decimal_len(t_float *f_nums);
void				float_dot(t_float *f_nums);
int					print_zeros_largel(int len);
int					ft_strlen_double(char *str);
void				float_count_precision(t_float *f_nums, t_struct *list);
void				check_prec_f(t_float *f_nums, t_struct *list);
void				float_print(t_float *f_nums, t_struct *list);
void				float_print_zeros(t_float *f_nums);
int					n_tu(int number, int count);
int					handle_f(t_struct *list, va_list va);
int					handle_fl(t_struct *list, va_list va);
int					ft_handling_unsigned_digit(t_struct *list, void *digit);
int					ft_handling_x(t_struct *list, void *digit);
int					ft_handling_o(t_struct *list, void *digit);
int					ft_handling_ptr(t_struct *list, void *digit);
int					ft_handling_f(t_struct *list, va_list va);
int					ft_out(t_struct *list, va_list va);
int					continue_digit(const char *format, int i);
int					check_flags(const char *format, int i);
int					check_format(const char *format, int i);

#endif
