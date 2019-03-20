/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_shifter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:46:51 by apasos-g          #+#    #+#             */
/*   Updated: 2019/03/08 11:09:15 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		shiftable_up(char ***tetri)
{
	int i;

	i = 0;
	while ((*tetri)[0][i])
	{
		if ((*tetri)[0][i] == '#')
			return (0);
		i++;
	}
	return (1);
}

int		shiftable_left(char ***tetri)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if ((*tetri)[i][0] == '#')
			return (0);
		i++;
	}
	return (1);
}

void	shift_up(char ***tetri)
{
	(*tetri)[0] = (*tetri)[1];
	(*tetri)[1] = (*tetri)[2];
	(*tetri)[2] = (*tetri)[3];
	(*tetri)[3] = ft_strdup("....");
}

void	shift_left(char ***tetri)
{
	int j;

	j = 0;
	while (j < 4)
	{
		if (j < 3)
		{
			(*tetri)[0][j] = (*tetri)[0][j + 1];
			(*tetri)[1][j] = (*tetri)[1][j + 1];
			(*tetri)[2][j] = (*tetri)[2][j + 1];
			(*tetri)[3][j] = (*tetri)[3][j + 1];
		}
		if (j == 3)
		{
			(*tetri)[0][j] = '.';
			(*tetri)[1][j] = '.';
			(*tetri)[2][j] = '.';
			(*tetri)[3][j] = '.';
		}
		j++;
	}
}

int		tetri_shifter(char ***tetri)
{
	int i;

	i = 0;
	while (i < 4 && shiftable_up(tetri))
	{
		shift_up(tetri);
		i++;
	}
	if (i == 4)
		return (0);
	i = 0;
	while (i < 4 && shiftable_left(tetri))
	{
		shift_left(tetri);
		i++;
	}
	if (i == 4)
		return (0);
	return (1);
}
