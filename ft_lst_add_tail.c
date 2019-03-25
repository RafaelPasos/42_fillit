/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_tail.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 23:50:32 by apasos-g          #+#    #+#             */
/*   Updated: 2019/03/24 22:13:34 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_lst_add_tail(t_tetrimino **lst, t_tetrimino **new_tetri)
{
	t_tetrimino	*temp;

	if (!(*lst))
	{
		*lst = *new_tetri;
	}
	else
	{
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = *new_tetri;
	}
}
