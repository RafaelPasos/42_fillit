/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 21:57:57 by apasos-g          #+#    #+#             */
/*   Updated: 2019/03/27 20:03:28 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_tetrimino	*lst;

	lst = NULL;
	if (argc != 2)
	{
		write(1, "usage: ./fillit [filename]\n", 27);
		return (0);
	}
	lst = parsero(argv[1]);
	if (lst != NULL)
	{
		solver(&lst);
		ft_empty_lst(&lst);
	}
	else
		write(1, "error\n", 7);
	return (0);
}
