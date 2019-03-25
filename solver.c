/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 06:11:26 by apasos-g          #+#    #+#             */
/*   Updated: 2019/03/23 22:00:38 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int solvethis(t_tetrimino **lst, t_map map, int letter)
{
	int	coords[2];
	int x;
	int y;

	if (*lst == NULL)
	{
		print_tetr(&(map.map), map.size);
		return (1);
	}
	y = 0;
	while (y < map.size)
	{
		x = 0;
		coords[1] = y;
		while (x < map.size)
		{
			coords[0] = x;
			if (place_tetrimino(&map, lst, coords, letter))
				if (solvethis(&((*lst)->next), map, letter + 1))
					return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	solver(t_tetrimino **lst)
{
	int		size;
	t_map	*initialmap;
	int		letter;

	letter = 0;
	size = grid_size(lst);
	initialmap = (t_map *)malloc(sizeof(t_map));
	initialmap->map = grid_builder(size);
	initialmap->size = size;
	while (!(solvethis(lst, *initialmap, letter)))
	{
		ft_free2darray(&(initialmap->map), size);
		size++;
		initialmap->map = grid_builder(size);
		initialmap->size = size;
	}
	ft_free2darray(&(initialmap->map), size);
	free(initialmap);
	return (1);
}
