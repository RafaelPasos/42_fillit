/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_tetris.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 01:10:11 by apasos-g          #+#    #+#             */
/*   Updated: 2019/03/24 22:55:54 by raramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_count_tetris(t_tetrimino **lst)
{
	t_tetrimino	*iterator;
	int			count;

	count = 0;
	iterator = *lst;
	while (iterator)
	{
		iterator = iterator->next;
		count++;
	}
	return (count);
}
