/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 21:21:48 by apasos-g          #+#    #+#             */
/*   Updated: 2019/03/24 22:19:33 by apasos-g         ###   ########.fr       */
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

/*
 *
 *
 *
 * BORRA LAS LIBRERIAS PERRO
 */

typedef	struct		s_tetrim
{
	unsigned short	val;
	int				height;
	int				width;
	char			**shape;
	struct s_tetrim	*next;
}					t_tetrimino;

typedef struct		s_map
{
	char			**map;
	int				size;
}					t_map;

t_tetrimino			*get_tetrimino(int fd, t_tetrimino **lst, int *status);
int					tetrivalue(char ***tetri, unsigned short *val);
int					charvalidator(char	***tetri);
int					tetri_shifter(char ***tetri);
void				shift_left(char ***tetri);
void				shift_up(char ***tetri);
int					shiftable_left(char ***tetri);
int					shiftable_up(char ***tetri);
unsigned short		tetri_validator(unsigned short n);
unsigned short		tetri_validator2(unsigned short n);
int					readfromfile(int fd, char ***tetri, int readn);
t_tetrimino			*parsero(char *filename);
int					check_new_line(int fd, char **line, \
					t_tetrimino **lst, int tetri);
void				ft_lst_add_tail(t_tetrimino **lst, t_tetrimino **new_tetri);
t_tetrimino			*ft_remove_lst_head(t_tetrimino **lst);
void				ft_empty_lst(t_tetrimino **lst);
void				print_tetr(char ***tetri, int size);
int					ft_count_tetris(t_tetrimino **lst);
int					grid_size(t_tetrimino **lst);
int					get_max_size(char ***tetri);
char				**grid_builder(int size);
int					solver(t_tetrimino **lst);
int					solvethis(t_tetrimino **lst, t_map map, int letter);
unsigned short		power_of_2(unsigned short pow);
void				place_it(t_map *mapa, t_tetrimino **lst, \
					int coords[2], int letter);
int					place_tetrimino(t_map *map, t_tetrimino **lst, \
					int coords[2], int letter);
int					get_width(unsigned short val);
int					get_height(unsigned short val);
t_tetrimino			*new_tetrimino(char ***ntetri, unsigned short v);

#endif
