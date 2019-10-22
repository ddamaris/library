/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 20:04:12 by ddamaris          #+#    #+#             */
/*   Updated: 2019/10/01 20:04:18 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{
	int fd1;
	int fd2;
	char *line = "Hi";
	int status;
	int i;

	//	fd = open("C:\\Users\\YZU\\Documents\\Coding\\working\\some_lines.txt", O_RDONLY);
	fd1 = open("/Users/ddamaris/coding/stock/Get_next_line/test.txt", O_RDONLY);
	fd2 = open("/Users/ddamaris/coding/stock/Get_next_line/large_file.txt", O_RDONLY);
	i = 0;
	while (i++ < 1000)
	{
		if ((status = get_next_line(fd2, &line)) == 1)
			printf("fd2 %d\t\t%s\n", i, line);

		//		if ((status = get_next_line(fd1, &line)) == 1)
		//			printf("fd1 %d %s\n", i, line);
	}
	close(fd1);
	close(fd2);
	return (0);
}