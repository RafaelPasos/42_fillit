/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 03:46:06 by apasos-g          #+#    #+#             */
/*   Updated: 2019/03/21 06:45:25 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	get_max_size(char ***tetri)
{
	unsigned short	value;
	unsigned short	base;
	int				i;
	int				j;

	i = 0;
	value = 0;
	base = 1;
	while (i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if ((*tetri)[i][j] == '#')
				value = value + base;
			base = base * 2;
		}
		i++;
	}
	if (value == 51)
		return (2);
	if (value == 4369 || value == 15)
		return (4);
	return (3);
}

int grid_size(t_tetrimino **lst)
{
	int root;
	int count;
	int size1;
	int size2;

	count = ft_count_tetris(lst);
	root = 0;
	if (count > 2)
	{
		root = 2;
		while (root * root < (count * 4))
			root++;
		return (root);
	}
	else if (count == 2)
	{
		size1 = get_max_size(&((*lst)->shape));
		size2 = get_max_size(&((*lst)->next->shape));
		return ((size1 > size2) ? size1 : size2);
	}
	else
		return (get_max_size(&((*lst)->shape)));
}
