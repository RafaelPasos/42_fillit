/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 21:57:57 by apasos-g          #+#    #+#             */
/*   Updated: 2019/03/20 01:32:50 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int			i;
	int			j;
	t_tetrimino	*lst;
	t_tetrimino *print;

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
		{
			/*
			while ((print = ft_remove_lst_head(&lst)))
			{
				print_tetr(&(print->shape));
			}
			*/
			//printf("%d tetriminos in dis file\n", ft_count_tetris(&lst));
			printf("File %d: OK\n", i);
		}
		else
			printf("File %d: Error\n", i);
		i++;
	}
	return (0);
}
