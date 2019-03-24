/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 21:13:03 by apasos-g          #+#    #+#             */
/*   Updated: 2019/03/21 20:23:33 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrimino	*parser(char *filename)
{
	int				fd;
	int				status;
	char			**tetrimin;
	unsigned short	value;
	t_tetrimino		*lst;

	fd = open(filename, O_RDONLY);
	lst = NULL;
	while ((status = get_tetrimino(fd, &tetrimin, &lst, &value)) != 0)
	{
		if (status == -1)
		{
			ft_empty_lst(&lst);
			return (NULL);
		}
		if (status == 0)
			return (lst);
		else
		{
			ft_lst_add_tail(&lst, &tetrimin, value);
		}
	}
	return (lst);
}
