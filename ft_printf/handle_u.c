
#include "ft_printf.h"

static char				ft_size_uns_digit(uintmax_t digit)
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

static char				ft_strlen_uns_digit(t_struct *list, intmax_t digit)
{
	char				res;
	char				tmp;

	tmp = 0;
	res = ft_size_uns_digit(digit);
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
	return (res);
}

static char				ft_print_uns_digit(uintmax_t digit, t_struct *list)
{
	char				len;

	len = 0;
	if (digit == 0 && list->prec == -2)
		return (0);
	if (digit >= 10)
	{
		len += ft_print_uns_digit(digit / 10, list);
		len += ft_print_char((digit % 10) + '0');
	}
	else
		len += ft_print_char(digit + '0');
	return (len);
}

static char				ft_hend_uns_digit(t_struct *list, uintmax_t digit)
{
	short				len;

	len = 0;
	if (list->zero == '0' && list->prec == -1)
		list->morezero = '0';
	list->size = ft_strlen_uns_digit(list, digit);
	while (list->minus != '-' && list->width > list->size)
		len += ft_print_char(list->morezero) && list->width--;
	while (list->prec != -1 && list->prec > 0)
		(len += ft_print_char('0')) && list->prec--;
	len += ft_print_uns_digit(digit, list);
	while (list->width > list->size && list->minus == '-')
		(len += ft_print_char(' ')) && list->width--;
	return (len);
}

int						ft_handling_unsigned_digit(t_struct *list, void *digit)
{
	if (list->ll)
		return (ft_hend_uns_digit(list, (unsigned long long)digit));
	else if (list->l)
		return (ft_hend_uns_digit(list, (unsigned long)digit));
	else if (list->h)
		return (ft_hend_uns_digit(list, (unsigned short)digit));
	else if (list->hh)
		return (ft_hend_uns_digit(list, (unsigned char)digit));
	else
		return (ft_hend_uns_digit(list, (unsigned int)digit));
}
