/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 06:11:26 by apasos-g          #+#    #+#             */
/*   Updated: 2019/03/27 19:34:18 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	solvethis(t_tetrimino **lst, t_map *map, int letter)
{
	t_point	point;

	if (*lst == NULL)
	{
		print_tetr(&(map->map), map->size);
		return (1);
	}
	point.height = 0;
	while (point.height < map->size)
	{
		point.width = 0;
		while (point.width < map->size)
		{
			if (place_tetrimino(map, lst, point, letter))
			{
				if (solvethis(&((*lst)->next), map, letter + 1))
					return (1);
				else
					place_fix(map, lst, point);
			}
			point.width++;
		}
		point.height++;
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
	while (!(solvethis(lst, initialmap, letter)))
	{
		ft_free2darray(&(initialmap->map), size);
		initialmap->map = NULL;
		size++;
		initialmap->map = grid_builder(size);
		initialmap->size = size;
	}
	ft_free2darray(&(initialmap->map), size);
	free(initialmap);
	return (1);
}
