/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:52:58 by ddamaris          #+#    #+#             */
/*   Updated: 2019/10/18 12:05:30 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 547

# include "libft/libft.h"

int		map_size(char *map);
int		*ft_strintdup(int *s1, int n);
int		*vld_ttrm(char *s);
int		checker(char *bf);
void	put_ttrm(char *map, int *ttrm, int ms, char ch);
char	*map_init(int ms);
int		right_place(char *map, int *ttrm, int ms);
int		draw_map(int **lst, char *map, int nb, int i);
int		make_map(int **tt_list, int nb);
int		ft_exit(void);
int		**make_list(char *bf, int n);
int		free_list(int **lst, int i);

#endif
