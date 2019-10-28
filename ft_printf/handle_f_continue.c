
#include "ft_printf.h"

int		ft_strlen_double(char *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
		{
			while (str[i] != '\0')
			{
				len++;
				i++;
			}
		}
		i++;
	}
	return (len);
}

void	float_count_precision(t_float *f_nums, t_struct *list)
{
	f_nums->i = 0;
	f_nums->k = 7 - f_nums->len - (6 - list->prec);
	if (list->prec > 6)
		f_nums->k = 7 - f_nums->len - (6 - list->prec);
	if (list->morezero == 1)
		f_nums->k = f_nums->k - 1;
}

void	check_prec_f(t_float *f_nums, t_struct *list)
{
	if (list->prec != -1)
	{
		f_nums->len = list->prec + 1;
		list->res = 1;
	}
	while (f_nums->len-- > 1 && f_nums->r[f_nums->i++] != '\0')
	{
		write(1, &f_nums->r[f_nums->i], 1);
	}
}

void	float_print_zeros(t_float *f_nums)
{
	while (f_nums->k > 0)
	{
		write(1, "0", 1);
		f_nums->k--;
	}
}

int		check_one(t_float *f_nums)
{
	if (f_nums->f == 1.000000)
	{
		write(1, "1.000000", 8);
		return (1);
	}
	else
	{
		return (0);
	}
}
