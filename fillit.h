/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 21:21:48 by apasos-g          #+#    #+#             */
/*   Updated: 2019/03/20 00:09:06 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef	struct		s_tetrim
{
	char			**shape;
	struct s_tetrim	*next;
}					t_tetrimino;

int					get_tetrimino(int fd, char ***tetrimin, \
					t_tetrimino **lst);
int					tetrivalue(char ***tetri);
int					charvalidator(char	***tetri);
int					tetri_shifter(char ***tetri);
void				shift_left(char ***tetri);
void				shift_up(char ***tetri);
int					shiftable_left(char ***tetri);
int					shiftable_up(char ***tetri);
unsigned short		tetri_validator(unsigned short n);
unsigned short		tetri_validator2(unsigned short n);
int					readfromfile(int fd, char ***tetri, int readn);
t_tetrimino			*parser(char *filename);
int					check_new_line(int fd, char **line, \
					t_tetrimino **lst, int tetri);
void				ft_lst_add_tail(t_tetrimino **lst, char ***ntetri);
t_tetrimino			*ft_remove_lst_head(t_tetrimino **lst);
void				ft_empty_lst(t_tetrimino **lst);
void				print_tetr(char ***tetri);

#endif
