/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_empty_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 23:55:07 by apasos-g          #+#    #+#             */
/*   Updated: 2019/03/13 12:05:13 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_empty_lst(t_tetrimino **lst)
{
	t_tetrimino *cur;
	t_tetrimino	*nxt;

	cur = *lst;
	while (cur)
	{
		nxt = cur->next;
		free(cur);
		cur = nxt;
	}
}