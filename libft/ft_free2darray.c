/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2darray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 05:25:25 by apasos-g          #+#    #+#             */
/*   Updated: 2019/03/24 19:00:22 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free2darray(char ***array, size_t col)
{
	size_t i;

	i = 0;
	while (i < col)
	{
		//free((*array)[i]);
		ft_strdel(&((*array)[i]));
		i++;
	}
	free(*array);
	//ft_strdel(*array);
}
