/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_tetrimino.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 21:12:16 by apasos-g          #+#    #+#             */
/*   Updated: 2019/03/24 21:54:50 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrimino	*new_tetrimino(char ***ntetri, unsigned short v)
{
	t_tetrimino	*new_tetri;
	int			i;

	new_tetri = (t_tetrimino *)malloc(sizeof(t_tetrimino));
	new_tetri->shape = (char **)malloc(sizeof(char *) * 4);
	i = 0;
	while (i < 4)
	{
		(new_tetri->shape)[i] = ft_strdup((*ntetri)[i]);
		i++;
	}
	new_tetri->val = v;
	new_tetri->height = get_height(v);
	new_tetri->width = get_width(v);
	new_tetri->next = NULL;
	return (new_tetri);
}
