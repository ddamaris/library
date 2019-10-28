
#include "ft_printf.h"

void	float_print(t_float *f_nums, t_struct *list)
{
	while (f_nums->r[f_nums->i] != '\0')
	{
		if (f_nums->f == 0 && list->prec == -1)
		{
			write(1, "0.000000", 8);
			break ;
		}
		if (f_nums->f == 0 && list->prec != -1)
			write(1, "0", 1);
		write(1, &f_nums->r[f_nums->i], 1);
		if (f_nums->r[f_nums->i] == '.')
		{
			check_prec_f(f_nums, list);
			if (list->res == 1)
			{
				list->res = 0;
				break ;
			}
		}
		f_nums->i++;
		if (f_nums->r[f_nums->i] == '.' && list->morezero == 1)
			break ;
	}
}

void	innitiaize_struct_float(t_float *f_nums)
{
	f_nums->length = 0;
	f_nums->length2 = 0;
	f_nums->number = 0;
	f_nums->i = 0;
	f_nums->position = 0;
	f_nums->sign = 0;
	f_nums->number2 = 0;
	f_nums->number3 = 0;
	f_nums->f = 0;
	f_nums->p = 0;
	f_nums->len = 0;
	f_nums->k = 0;
	f_nums->r = NULL;
	f_nums->str = NULL;
}

void	check_sum(t_float *f_nums)
{
	if (f_nums->number - (int)f_nums->number != 0.0 ||
		f_nums->number - (int)f_nums->number != 0.00 ||
		f_nums->number - (int)f_nums->number != 0.000 ||
		f_nums->number - (int)f_nums->number != 0.0000 ||
		f_nums->number - (int)f_nums->number != 0.00000 ||
		f_nums->number - (int)f_nums->number != 0.000000)
		f_nums->number += 1;
}

int		handle_fl(t_struct *list, va_list va)
{
	int		len;
	t_float	f_nums;

	innitiaize_struct_float(&f_nums);
	f_nums.f = va_arg(va, long double);
	if (f_nums.f == 1.000000)
	{
		write(1, "1.000000", 8);
		return (8);
	}
	float_tenth_len(&f_nums);
	float_decimal_len(&f_nums);
	f_nums.r = malloc(sizeof(char *) * f_nums.length);
	check_sum(&f_nums);
	float_dot(&f_nums);
	f_nums.len = ft_strlen_double(f_nums.r);
	float_count_precision(&f_nums, list);
	float_print(&f_nums, list);
	float_print_zeros(&f_nums);
	free(f_nums.r);
	len = (int)f_nums.length;
	len = print_zeros_largel(len);
	return (len);
}

int		handle_f(t_struct *list, va_list va)
{
	int		len;
	t_float	f_nums;

	innitiaize_struct_float(&f_nums);
	f_nums.f = va_arg(va, double);
	if (check_one(&f_nums) == 1)
		return (8);
	float_tenth_len(&f_nums);
	float_decimal_len(&f_nums);
	f_nums.r = malloc(sizeof(char *) * f_nums.length);
	float_dot(&f_nums);
	f_nums.len = ft_strlen_double(f_nums.r);
	float_count_precision(&f_nums, list);
	float_print(&f_nums, list);
	if (f_nums.r[f_nums.length] == '\0' && f_nums.r[f_nums.length - 1] == '.')
	{
		write(1, "000000", 6);
		return (f_nums.length + 6);
	}
	float_print_zeros(&f_nums);
	len = (int)f_nums.length;
	free(f_nums.r);
	return (len);
}
