/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tetrimino.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:08:57 by apasos-g          #+#    #+#             */
/*   Updated: 2019/03/27 19:13:03 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	place_fix(t_map *mapa, t_tetrimino **lst, \
				t_point p)
{
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
				mapa->map[p.height + i][p.width + k] = '.';
			k++;
		}
		i++;
	}
}

void	place_it(t_map *mapa, t_tetrimino **lst, \
				t_point p, int letter)
{
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
				mapa->map[p.height + i][p.width + k] = 'A' + letter;
			k++;
		}
		i++;
	}
}

int		place_tetrimino(t_map *mapa, t_tetrimino **lst, \
				t_point p, int letter)
{
	int	i;
	int	k;
	int	freespots;

	if (mapa->size - p.height < ((*lst)->height) || \
			mapa->size - p.width < ((*lst)->width))
		return (0);
	freespots = 0;
	i = 0;
	while (i < 4)
	{
		k = 0;
		while (k < 4)
		{
			if ((*lst)->shape[i][k] == '#')
				if (mapa->map[p.height + i][p.width + k] != '.')
					return (0);
			k++;
		}
		i++;
	}
	place_it(mapa, lst, p, letter);
	return (1);
}
