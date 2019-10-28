
#include "ft_printf.h"

static char			ft_size_x_digit(intmax_t digit)
{
	char			res;

	res = 1;
	digit /= 16;
	while (digit)
	{
		digit /= 16;
		res++;
	}
	return (res);
}

static char			ft_strlen_x_digit(t_struct *list, intmax_t digit)
{
	char			res;
	char			tmp;

	tmp = 0;
	res = ft_size_x_digit(digit);
	if (list->prec != -1 && list->prec > res)
	{
		tmp = (list->prec - res);
		res = list->prec;
	}
	if (list->hash == '#' && digit != 0)
		res += 2;
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

static char			ft_print_x(uintmax_t digit, t_struct *list, char *base)
{
	char			len;

	len = 0;
	if (digit == 0 && list->prec == -2)
		return (0);
	if (digit >= 16)
	{
		len += ft_print_x(digit / 16, list, base);
		len += ft_print_char(base[digit % 16]);
	}
	else
		len += ft_print_char(base[digit % 16]);
	return (len);
}

static short		ft_hend_x_digit(t_struct *list, uintmax_t digit)
{
	short			len;

	len = 0;
	if (list->zero == '0' && list->prec == -1)
		list->morezero = '0';
	list->size = ft_strlen_x_digit(list, digit);
	if (list->morezero == '0' && list->hash == '#' && digit != 0)
		len += (list->spec == 'X') ? (ft_print_str("0X", -1)) :
		(ft_print_str("0x", -1));
	while (list->minus != '-' && list->width > (list->size))
		(len += ft_print_char(list->morezero)) && list->width--;
	if ((list->morezero == ' ' && list->hash == '#' && digit != 0))
		len += (list->spec == 'X') ? (ft_print_str("0X", -1)) :
		(ft_print_str("0x", -1));
	while (list->prec != -1 && list->prec > 0)
		(len += ft_print_char('0')) && list->prec--;
	len += (list->spec == 'X') ? ft_print_x(digit, list, "0123456789ABCDEF") :
	ft_print_x(digit, list, "0123456789abcdef");
	while (list->width > list->size && list->minus == '-')
		(len += ft_print_char(' ')) && list->width--;
	return (len);
}

int					ft_handling_x(t_struct *list, void *digit)
{
	if (list->ll)
		return (ft_hend_x_digit(list, (unsigned long long)digit));
	else if (list->l)
		return (ft_hend_x_digit(list, (unsigned long)digit));
	else if (list->h)
		return (ft_hend_x_digit(list, (unsigned short)digit));
	else if (list->hh)
		return (ft_hend_x_digit(list, (unsigned char)digit));
	else
		return (ft_hend_x_digit(list, (unsigned int)digit));
}
