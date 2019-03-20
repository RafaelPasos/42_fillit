/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 21:57:57 by apasos-g          #+#    #+#             */
/*   Updated: 2019/03/18 23:25:27 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int			i;
	t_tetrimino	*lst;

	i = 0;
	if (argc < 2)
	{
		printf("Error: specify at least 1 file\n");
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		lst = parser(argv[i]);
		if (lst != NULL)
			printf("File %d: OK\n", i);
		else
			printf("File %d: Error\n", i);
		i++;
	}
	return (0);
}
