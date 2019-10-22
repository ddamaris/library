/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <ddamaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:15:50 by ddamaris          #+#    #+#             */
/*   Updated: 2019/09/17 13:45:50 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int				i;
	unsigned long	res;
	int				m;

	i = 0;
	res = 0;
	m = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' ||
			str[i] == '\n' || str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i - 1] == '-')
		m = -1;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - '0');
		if (res > 9223372036854775807 && m == 1)
			return (-1);
		if (res > 9223372036854775807 && m == -1)
			return (0);
		if (res == 9223372036854775807 && m == -1)
			return (1);
	}
	return ((int)res * m);
}
