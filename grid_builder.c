/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_builder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 06:27:45 by apasos-g          #+#    #+#             */
/*   Updated: 2019/03/23 16:15:31 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**grid_builder(int size)
{
	char	**grid;
	int		i;
	int		k;

	i = 0;
	if (!(grid = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		if (!(grid[i] = (char *)malloc(sizeof(char) * (size + 1))))
		{
			ft_free2darray(&grid, i);
			return (NULL);
		}
		k = 0;
		while (k < size)
		{
			grid[i][k] = '.';
			k++;
		}
		grid[i][k] = '\0';
		i++;
	}
	grid[i] = NULL;
	return (grid);
}
