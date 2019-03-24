/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetri_dimensions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 20:28:37 by apasos-g          #+#    #+#             */
/*   Updated: 2019/03/22 14:45:45 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int get_height(unsigned short val)
{
	if (val == 275 || val == 547 || val == 785 || val == 802 || val == 306 || \
		val == 561 || val == 305 || val == 562)
		 return (3);
	if (val == 71 || val == 232 || val == 113 || val == 23 || val == 51 || \
		val == 108 || val == 99 || val == 39 || val == 114)
		 return (2);
	if (val == 15)
		return (1);
	else
		return (4);
}

int get_width(unsigned short val)
{
	if (val == 71 || val == 232 || val == 113 || val == 23 || val == 108 || \
		val == 99 || val == 39 || val == 114)
		 return (3);
	if (val == 275 || val == 547 || val == 785 || val == 802 || val == 51 || \
		val == 306 || val == 561 || val == 305 || val == 562)
		 return (2);
	if (val == 15)
		return (4);
	else
		return (1);
}
