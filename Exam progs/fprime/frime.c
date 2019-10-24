/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:17:08 by ddamaris          #+#    #+#             */
/*   Updated: 2019/10/24 13:37:21 by ddamaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char *argv[])
{
	int		i;
	int		nbr;

	if (argc == 2)
	{
		i = 2;
		nbr = atoi(argv[1]);
		if (nbr == 1)
			printf("1");
		while (nbr >= i)
		{
			if (nbr % i == 0)
			{
				printf("%d", i);
				if (nbr == i)
					break ;
				printf("*");
				nbr = nbr / i;
			}
			else
				i++;
		}
	}
	printf("\n");
	return (0);
}
