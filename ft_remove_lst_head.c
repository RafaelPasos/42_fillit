/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_lst_head.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 23:54:23 by apasos-g          #+#    #+#             */
/*   Updated: 2019/03/23 21:53:10 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrimino	*ft_remove_lst_head(t_tetrimino **lst)
{
	t_tetrimino	*temp;
	t_tetrimino *t;

	if (*lst)
	{
		t = *lst;
		temp = *lst;
		*lst = temp->next;
		ft_memdel((void**)&t);
		return (temp);
	}
	else
		return (NULL);
}
