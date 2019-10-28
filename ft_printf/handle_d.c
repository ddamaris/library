
#include "ft_printf.h"

static char				ft_size_digit(intmax_t digit)
{
	char				res;

	res = 1;
	digit /= 10;
	while (digit)
	{
		digit /= 10;
		res++;
	}
	return (res);
}

static char				ft_strlen_digit(t_struct *list, intmax_t digit)
{
	char				res;
	char				tmp;

	tmp = 0;
	res = ft_size_digit(digit);
	if (list->prec != -1 && list->prec > res)
	{
		tmp = (list->prec - res);
		res = list->prec;
	}
	if (tmp > 0)
		list->prec = tmp;
	else if (digit == 0 && list->prec == 0)
	{
		list->prec = -2;
		res = 0;
	}
	else
		list->prec = -1;
	if ((digit < 0) || ((list->plus == '+' || list->blank == ' ') &&
	digit >= 0))
		res++;
	return (res);
}

static char				ft_print_digit(intmax_t digit, t_struct *list)
{
	char len;

	len = 0;
	if (digit == 0 && list->prec == -2)
		return (0);
	if (-10 < digit && digit < 10)
		len += ft_print_char(ABS(digit) + '0');
	else
	{
		len += ft_print_digit(digit / 10, list);
		len += ft_print_digit(digit % 10, list);
	}
	return (len);
}

static short			ft_hend_digit(t_struct *list, intmax_t digit, int *len)
{
	if (list->zero == '0' && list->prec == -1)
		list->morezero = '0';
	list->size = ft_strlen_digit(list, digit);
	if (digit < 0 && list->morezero == '0')
		*len += ft_print_char('-');
	else if (digit >= 0 && list->morezero == '0' && list->plus == '+')
		*len += ft_print_char('+');
	else if (list->morezero == '0' && list->blank == ' ')
		*len += ft_print_char(' ');
	while (list->minus != '-' && list->width > list->size)
		(*len += ft_print_char(list->morezero)) && list->width--;
	if (list->plus == '+' && digit >= 0 && list->morezero != '0')
		*len += ft_print_char('+');
	else if (digit < 0 && list->morezero == ' ' && list->morezero != '0')
		*len += ft_print_char('-');
	else if (list->blank == ' ' && digit >= 0 && list->morezero != '0')
		*len += ft_print_char(' ');
	while (list->prec != -1 && list->prec > 0)
		(*len += ft_print_char('0')) && list->prec--;
	*len += ft_print_digit(digit, list);
	while (list->width > list->size && list->minus == '-')
		(*len += ft_print_char(' ')) && list->width--;
	return (*len);
}

int						ft_handling_digit(t_struct *list, void *digit)
{
	int len;

	len = 0;
	if (list->ll)
		(ft_hend_digit(list, (long long)digit, &len));
	else if (list->l)
		(ft_hend_digit(list, (long)digit, &len));
	else if (list->h)
		(ft_hend_digit(list, (short)digit, &len));
	else if (list->hh)
		(ft_hend_digit(list, (char)digit, &len));
	else
		(ft_hend_digit(list, (int)digit, &len));
	return (len);
}
