/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 21:13:03 by apasos-g          #+#    #+#             */
/*   Updated: 2019/03/25 20:59:27 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrimino	*parsero(char *filename)
{
	int				fd;
	t_tetrimino		*lst;
	t_tetrimino		*toadd;
	int				status;

	fd = open(filename, O_RDONLY);
	status = 0;
	lst = NULL;
	toadd = NULL;
	while ((toadd = get_tetrimino(fd, &lst, &status)))
	{
		ft_lst_add_tail(&lst, &toadd);
		toadd = NULL;
	}
	if (status == -1)
		ft_empty_lst(&lst);
	return (lst);
}
