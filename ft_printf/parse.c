
#include "ft_printf.h"

void	found_h_hh_l_ll(const char *format, int i, t_struct *list)
{
	if (format[i] == 'h' && format[i + 1] != 'h' && format[i - 1] != 'h')
	{
		list->h = 'h';
		list->len++;
	}
	if (format[i] == 'h' && format[i + 1] == 'h')
	{
		list->hh = 'y';
		list->len = list->len + 2;
	}
	if (format[i] == 'l' && format[i + 1] != 'l' && format[i - 1] != 'l')
	{
		list->l = 'l';
		list->len++;
	}
	if (format[i] == 'l' && format[i + 1] == 'l')
	{
		list->ll = 'y';
		list->len = list->len + 2;
	}
	if (format[i] == 'L')
	{
		list->largel = 1;
		list->len = list->len + 1;
	}
}

void	found_prec(const char *s, int i, t_struct *list)
{
	list->len++;
	list->prec = 0;
	while (s[i] >= 48 && s[i] <= 57)
	{
		list->prec = list->prec * 10;
		list->prec = list->prec + ((int)s[i] - '0');
		i++;
		list->len++;
	}
}

void	found_number(const char *s, int i, t_struct *list)
{
	list->width = 0;
	while (s[i] >= 48 && s[i] <= 57)
	{
		list->width = list->width * 10;
		list->width = list->width + ((int)s[i] - '0');
		i++;
		list->len++;
	}
}

int		pa(const char *format, int i, va_list va, t_struct *list)
{
	define_list(list);
	while (check_format(format, i) == 1)
	{
		if (check_flags(format, i) == 1)
			found_flags(format, i, list);
		if (format[i] >= 49 && format[i] <= 57)
		{
			found_number(format, i, list);
			i = continue_digit(format, i) - 1;
		}
		if (format[i] == '.')
		{
			found_prec(format, (i + 1), list);
			i = continue_digit(format, (i + 1)) - 1;
		}
		if (format[i] == 'h' || format[i] == 'l' || format[i] == 'L')
			found_h_hh_l_ll(format, i, list);
		i++;
	}
	parse_format_c(format, i, list);
	return (ft_out(list, va));
}
