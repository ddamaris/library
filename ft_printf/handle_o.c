
#include "ft_printf.h"

static char			ft_size_o_digit(intmax_t digit)
{
	char			res;

	res = 1;
	digit /= 8;
	while (digit)
	{
		digit /= 8;
		res++;
	}
	return (res);
}

static char			ft_strlen_o_digit(t_struct *list, intmax_t digit)
{
	char			res;
	char			tmp;

	tmp = 0;
	res = ft_size_o_digit(digit);
	if (list->prec != -1 && list->prec > res)
	{
		tmp = (list->prec - res);
		res = list->prec;
	}
	if (list->hash == '#' && digit != 0)
		res += 1;
	if (tmp > 0)
		list->prec = tmp;
	else if (digit == 0 && list->prec == 0 && list->hash != '#')
	{
		list->prec = -2;
		res = 0;
	}
	else
		list->prec = -1;
	return (res);
}

static char			print_o_dig(uintmax_t digit, t_struct *list, char *base)
{
	char			len;

	len = 0;
	if (digit == 0 && list->prec == -2)
		return (0);
	if (digit >= 8)
	{
		len += print_o_dig(digit / 8, list, base);
		len += ft_print_char(base[digit % 8]);
	}
	else
		len += ft_print_char(base[digit % 8]);
	return (len);
}

static short		ft_hend_o_digit(t_struct *list, uintmax_t digit)
{
	short			len;

	len = 0;
	if (list->zero == '0' && list->prec == -1)
		list->morezero = '0';
	list->size = ft_strlen_o_digit(list, digit);
	if (list->morezero == '0' && list->hash == '#' && digit != 0)
		len += ft_print_char('0');
	while (list->minus != '-' && list->width > (list->size))
		len += ft_print_char(list->morezero) && list->width--;
	if (list->morezero == ' ' && list->hash == '#' && digit != 0)
		len += ft_print_char('0');
	while (list->prec != -1 && list->prec > 0)
		(len += ft_print_char('0')) && list->prec--;
	len += print_o_dig(digit, list, "01234567");
	while (list->width > list->size && list->minus == '-')
		(len += ft_print_char(' ')) && list->width--;
	return (len);
}

int					ft_handling_o(t_struct *list, void *digit)
{
	if (list->ll)
		return (ft_hend_o_digit(list, (unsigned long long)digit));
	else if (list->l)
		return (ft_hend_o_digit(list, (unsigned long)digit));
	else if (list->h)
		return (ft_hend_o_digit(list, (unsigned short)digit));
	else if (list->hh)
		return (ft_hend_o_digit(list, (unsigned char)digit));
	else
		return (ft_hend_o_digit(list, (unsigned int)digit));
}
