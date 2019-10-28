
#include "ft_printf.h"

int		n_tu(int number, int count)
{
	int	result;

	result = 1;
	while (count-- > 0)
		result *= number;
	return (result);
}

void	float_tenth_len(t_float *f_nums)
{
	f_nums->sign = -1;
	if (f_nums->f < 0)
	{
		f_nums->sign = '-';
		f_nums->f *= -1;
		f_nums->length++;
	}
	f_nums->number2 = f_nums->f;
	f_nums->number = f_nums->f;
	f_nums->length = 0;
	f_nums->length2 = 0;
	while ((f_nums->number2 - (long double)f_nums->number) != 0.0 &&
		!((f_nums->number2 - (long double)f_nums->number) < 0.0)
		&& f_nums->length2 <= 5)
	{
		f_nums->number2 = f_nums->f * (n_tu(10.0, f_nums->length2 + 1));
		f_nums->number = f_nums->number2;
		f_nums->length2++;
	}
	f_nums->number3 = f_nums->f * (n_tu(10.0, f_nums->length2 + 1));
}

void	float_decimal_len(t_float *f_nums)
{
	while (f_nums->f > 1)
	{
		if (f_nums->length > -1)
			f_nums->f /= 10;
		f_nums->length++;
	}
	f_nums->position = f_nums->length;
	f_nums->length = f_nums->length + 1 + f_nums->length2;
	f_nums->number = f_nums->number2;
	if (f_nums->sign == '-')
	{
		f_nums->length++;
		f_nums->position++;
	}
}

void	float_dot(t_float *f_nums)
{
	f_nums->i = f_nums->length;
	while (f_nums->i >= 0)
	{
		if (f_nums->i == (f_nums->length))
			f_nums->r[f_nums->i] = '\0';
		else if (f_nums->i == (f_nums->position))
			f_nums->r[f_nums->i] = '.';
		else if (f_nums->sign == '-' && f_nums->i == 0)
			f_nums->r[f_nums->i] = '-';
		else
		{
			f_nums->r[f_nums->i] = (f_nums->number % 10) + '0';
			f_nums->number /= 10;
		}
		f_nums->i--;
	}
}

int		print_zeros_largel(int len)
{
	while (len > 2 && len < 8)
	{
		write(1, "0", 1);
		len++;
	}
	return (len);
}
