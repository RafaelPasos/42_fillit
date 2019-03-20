/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_tail.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 23:50:32 by apasos-g          #+#    #+#             */
/*   Updated: 2019/03/19 22:01:52 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_lst_add_tail(t_tetrimino **lst, char *** ntetri)
{
	t_tetrimino	*temp;
	t_tetrimino	*new_tetri;

	new_tetri = (t_tetrimino *)malloc(sizeof(t_tetrimino));
	new_tetri->shape = *ntetri;
	new_tetri->next = NULL;
	if (!(*lst))
	{
		*lst = new_tetri;
	}
	else
	{
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_tetri;
	}
}
