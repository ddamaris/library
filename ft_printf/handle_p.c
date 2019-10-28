
#include "ft_printf.h"

static char				ft_size_ptr_digit(intmax_t digit)
{
	char				res;

	res = 1;
	digit /= 16;
	while (digit)
	{
		digit /= 16;
		res++;
	}
	return (res);
}

static char				ft_strlen_ptr(t_struct *list, intmax_t digit)
{
	char				res;
	char				tmp;

	res = ft_size_ptr_digit(digit);
	tmp = 0;
	if (list->prec != -1 && list->prec > res)
	{
		tmp = (list->prec - res);
		res = list->prec;
	}
	if (digit != 0)
		res += 2;
	if (tmp > 0)
		list->prec = tmp;
	else if (digit == 0 && list->prec == 0)
	{
		list->prec = -2;
		res = 2;
	}
	else
		list->prec = -1;
	return (res);
}

static char				print_p(uintmax_t digit, t_struct *list, char *base)
{
	char				len;

	len = 0;
	if (digit == 0 && list->prec == -2)
		return (0);
	if (digit >= 16)
	{
		len += print_p(digit / 16, list, base);
		len += ft_print_char(base[digit % 16]);
	}
	else
		len += ft_print_char(base[digit % 16]);
	return (len);
}

static short			ft_hend_ptr(t_struct *list, uintmax_t digit)
{
	short				len;

	len = 0;
	if (list->zero == '0' && list->prec == -1)
		list->morezero = '0';
	list->size = ft_strlen_ptr(list, digit);
	if (list->morezero == '0')
		len += ft_print_str("0x", -1);
	while (list->minus != '-' && list->width > (list->size))
		len += ft_print_char(list->morezero) && list->width--;
	if (list->morezero == ' ')
		len += ft_print_str("0x", -1);
	while (list->prec != -1 && list->prec > 0)
		(len += ft_print_char('0')) && list->prec--;
	len += print_p(digit, list, "0123456789abcdef");
	while (list->width > list->size && list->minus == '-')
		(len += ft_print_char(' ')) && list->width--;
	return (len);
}

int						ft_handling_ptr(t_struct *list, void *digit)
{
	return (ft_hend_ptr(list, (uintmax_t)digit));
}
