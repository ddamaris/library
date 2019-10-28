
#include "ft_printf.h"

int		ft_handling_f(t_struct *list, va_list va)
{
	int	len;

	if (list->l)
		len = (handle_f(list, va));
	else if (list->largel)
		len = handle_fl(list, va);
	else
		len = (handle_f(list, va));
	return (len);
}

void	found_flags(const char *format, int i, t_struct *list)
{
	if (format[i] == '#')
	{
		list->hash = '#';
		list->len++;
	}
	else if (format[i] == '0')
	{
		list->zero = '0';
		list->len++;
	}
	else if (format[i] == '-')
	{
		list->minus = '-';
		list->len++;
	}
	else if (format[i] == '+')
	{
		list->plus = '+';
		list->len++;
	}
	else if (format[i] == ' ')
	{
		list->blank = ' ';
		list->len++;
	}
}
