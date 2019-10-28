
#include "ft_printf.h"

int		print_char(const char *format, int i)
{
	write(1, &format[i], 1);
	return (1);
}

int		ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}
