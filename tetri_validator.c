/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 19:23:10 by apasos-g          #+#    #+#             */
/*   Updated: 2019/03/25 20:52:20 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned short	tetri_validator2(unsigned short n)
{
	if (n == 54)
		return (1);
	if (n == 306)
		return (1);
	if (n == 99)
		return (1);
	if (n == 561)
		return (1);
	if (n == 39)
		return (1);
	if (n == 305)
		return (1);
	if (n == 114)
		return (1);
	if (n == 562)
		return (1);
	return (0);
}

unsigned short	tetri_validator(unsigned short n)
{
	if (n == 275)
		return (1);
	if (n == 547)
		return (1);
	if (n == 785)
		return (1);
	if (n == 71)
		return (1);
	if (n == 116)
		return (1);
	if (n == 802)
		return (1);
	if (n == 113)
		return (1);
	if (n == 23)
		return (1);
	if (n == 51)
		return (1);
	if (n == 4369)
		return (1);
	if (n == 15)
		return (1);
	return (tetri_validator2(n));
}
