/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 14:09:10 by ddamaris          #+#    #+#             */
/*   Updated: 2019/09/05 15:43:43 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#define BUF 4096

int	main(int argc, char **argv)
{
	int		rd;
	int		fd;
	char	str[BUF];

	if (argc == 1)
		ft_putstr("File name missing.\n");
	if (argc > 2)
		ft_putstr("Too many arguments.\n");
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			ft_putstr("Can't open file\n");
		else
		{
			rd = read(fd, str, BUF);
			str[rd] = '\0';
			ft_putstr(str);
			rd = close(fd);
		}
	}
	return (0);
}
