
#include "ft_printf.h"

/*int		print_char(const char *format, int i)
{
	write(1, &format[i], 1);
	return (1);
}

int		ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}
*/
int		ft_handling_char(t_struct *list, void *c)
{
	int	len;

	len = 0;
	if (list->zero == '0')
		list->morezero = '0';
	if (list->minus != '-' && list->width > 1)
		while ((list->width)-- - 1)
			len += ft_print_char(list->morezero);
	if (list->spec == 'c' && !list->l)
		len += ft_print_char((int)c);
	else if (list->spec == 'C' || (list->spec == 'c' && list->l))
		len += ft_print_char((int)c);
	else
		len += ft_print_char(list->spec);
	if (list->width > 1 && list->minus == '-')
		while ((list->width)-- - 1)
			len += ft_print_char(' ');
	return (len);
}
