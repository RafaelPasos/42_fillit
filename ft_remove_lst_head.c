/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_lst_head.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 23:54:23 by apasos-g          #+#    #+#             */
/*   Updated: 2019/03/11 02:13:50 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrimino	*ft_remove_lst_head(t_tetrimino **lst)
{
	t_tetrimino	*temp;

	if (*lst)
	{
		temp = *lst;
		*lst = temp->next;
		return (temp);
	}
	else
		return (NULL);
}
