/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2darray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 05:25:25 by apasos-g          #+#    #+#             */
/*   Updated: 2019/03/12 05:43:36 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free2darray(char ***array, size_t col)
{
	size_t i;

	i = 0;
	while (i < col)
	{
		if ((*array)[i])
		{
			free((*array)[i]);
			i++;
		}
		else
			break ;
	}
	free(*array);
}
