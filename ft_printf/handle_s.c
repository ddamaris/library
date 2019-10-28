
#include "ft_printf.h"

int		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s != NULL)
		while (s[i])
			i++;
	return (i);
}

int		ft_print_str(char *str, int precision)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (ft_print_str("(null)", precision));
	while (*str != '\0' && precision--)
	{
		len += ft_print_char(*str);
		str++;
	}
	return (len);
}

int		ft_handling_str(t_struct *list, void *str)
{
	int len;

	list->size = (str != NULL) ? ft_strlen((char *)str) : 6;
	len = 0;
	list->size = !list->prec ? list->width : list->size;
	if (list->zero == '0')
		list->morezero = '0';
	while (list->minus != '-' && list->width > list->size)
		len += ft_print_char(list->morezero) && (list->width)--;
	while (list->minus != '-' && list->width > list->prec &&
	list->prec != -1 && (list->size > list->prec))
		len += ft_print_char(list->morezero) && list->width--;
	if (list->spec == 's' && !list->l)
		len += ft_print_str((char *)str, list->prec);
	while (list->minus == '-' && list->width > list->size)
		len += ft_print_char(' ') && list->width--;
	while (list->minus == '-' && list->width > list->prec &&
	list->prec != -1 && (list->size-- - list->prec))
		len += ft_print_char(' ');
	return (len);
}
