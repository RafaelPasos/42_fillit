/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_tetris.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 01:10:11 by apasos-g          #+#    #+#             */
/*   Updated: 2019/03/20 01:31:27 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int ft_count_tetris(t_tetrimino **lst)
{
	int count;
	t_tetrimino *iterator;

	count = 0;
	iterator = *lst;
	while (iterator)
	{
		iterator = iterator->next;
		count++;
	}
	return (count);
}
