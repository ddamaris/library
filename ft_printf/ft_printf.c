
#include "ft_printf.h"

void			define_list(t_struct *list)
{
	list->plus = 0;
	list->morezero = ' ';
	list->minus = 0;
	list->hash = 0;
	list->zero = 0;
	list->blank = 0;
	list->width = -1;
	list->prec = -1;
	list->h = 0;
	list->hh = 0;
	list->l = 0;
	list->ll = 0;
	list->z = 0;
	list->j = 0;
	list->len = 0;
	list->largel = 0;
}

int				continue_digit(const char *format, int i)
{
	while (format[i] >= 48 && format[i] <= 57)
		i++;
	return (i);
}

int				check_flags(const char *format, int i)
{
	if (format[i] == '#' || format[i] == '0' || format[i] == '-'
		|| format[i] == '+' || format[i] == ' ')
		return (1);
	else
		return (0);
}

int				check_format(const char *format, int i)
{
	if (format[i] == '#' || format[i] == '0' || format[i] == '-'
		|| format[i] == '+' || format[i] == ' ' || format[i] == '.'
		|| (format[i] >= 48 && format[i] <= 57) || format[i] == 'h'
		|| format[i] == 'l' || format[i] == 'L')
		return (1);
	else
		return (0);
}

int				ft_printf(const char *format, ...)
{
	int			i;
	int			len;
	va_list		va;
	t_struct	list;

	i = 0;
	len = 0;
	va_start(va, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			len = len + print_char(format, i);
		else
		{
			if (format[i] == '%' && format[i + 1] == '\0')
				return (0);
			i++;
			len = len + pa(format, i, va, &list);
			i = i + list.len;
			list.len = 0;
		}
		i++;
	}
	va_end(va);
	return (len);
}
