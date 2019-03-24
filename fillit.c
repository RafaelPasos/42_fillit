/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 21:57:57 by apasos-g          #+#    #+#             */
/*   Updated: 2019/03/23 20:25:45 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	t_tetrimino	*lst;

	if (argc != 2)
	{
		printf("usage: ./fillit [filename]\n");
		return (0);
	}
	lst = parser(argv[1]);
	if (lst != NULL)
	{
		solver(&lst);
		ft_empty_lst(&lst);
	}
	else
		printf("error\n");
	return (0);
}
