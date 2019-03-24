/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tetrimino.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:08:57 by apasos-g          #+#    #+#             */
/*   Updated: 2019/03/23 16:05:45 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned short	power_of_2(unsigned short pow)
{
	int res;

	res = 1;
	while (pow)
	{
		res = res * 2;
		pow--;
	}
	return (res);
}

void			place_it(t_map *mapa, t_tetrimino **lst, \
				int coords[2], int letter)
{
	/*
	unsigned short i;

	i = 0;
	while (i < 16)
	{
		if (lst->val & power_of_2(i))
			mapa->map[coords[0] + (i / 4)][coords[1] + (i % 4)] = 'A' + letter;
		i++;
	}
	*/
	int i;
	int k;

	i = 0;
	k = 0;
	while (i < 4)
	{
		k = 0;
		while (k < 4)
		{
			if ((*lst)->shape[i][k] == '#')
				mapa->map[coords[1] + i][coords[0] + k] = 'A' + letter;
			k++;
		}
		i++;
	}
}

int				place_tetrimino(t_map *mapa, t_tetrimino **lst, \
				int coords[2], int letter)
{
	//unsigned short	i;
	//unsigned short	tetrval;
	int				i;
	int				k;
	int				size;
	int				freespots;
	t_tetrimino		*te;

	size = 0;
	i = 0;
	te = *lst;
	//tetrval = lst->val;
	//while (mapa->map[size])
		//size++;
	//size = mapa->size;
	//size--;
	//E WE, CHECA COMO SE CALCULA EL SIZE Y CUANDO SE HACE EL MAPA MAS GRANDE
	//size = mapa->size;
	if (mapa->size - coords[1] < (te->height) || \
			mapa->size - coords[0] < (te->width))
	{
		//printf("fuck placing tetrimino %d up with coords: %d, %d\n", letter + 1, coords[0], coords[1]);
		return (0);
	}
	freespots = 0;
	/*
	//printf("chequemos si se puede acomodar el las coord\n");
	 while (i < 16)
	{
		if (freespots < 4 && tetrval & power_of_2(i))
		{
			//printf("se mama esta madre: %d\n", tetrval & power_of_2(i));
			if (mapa->map[coords[0] + (i / 4)][coords[1] + (i % 4)] == '.')
			{
				freespots++;
			}
			//printf("no seg fault\n");
		}
		i++;
	}
	*/
	i = -1;
	while (++i < 4)
	{
		k = -1;
		while (++k < 4)
			if (te->shape[i][k] == '#' && \
					mapa->map[coords[1] + i][coords[0] + k] == '.')
				freespots++;
	}
	if (freespots == 4)
	{
		place_it(mapa, lst, coords, letter);
		return (1);
	}
	return (0);
}
