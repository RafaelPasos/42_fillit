/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetrimino.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 02:55:49 by raramos           #+#    #+#             */
/*   Updated: 2019/03/27 19:20:17 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			charvalidator(char ***tetri)
{
	int		i;
	int		j;
	char	*s;
	int		valid;

	i = 0;
	valid = 1;
	while (i < 4)
	{
		j = 0;
		s = (*tetri)[i];
		if (!s || ft_strlen(s) != 4)
			return (0);
		while (s[j])
		{
			if (s[j] != '#' && s[j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int			tetrivalue(char ***tetri, unsigned short *val)
{
	unsigned short	value;
	unsigned short	base;
	int				i;
	int				j;

	i = 0;
	value = 0;
	base = 1;
	if (charvalidator(tetri) == 0 || tetri_shifter(tetri) == 0)
		return (-1);
	while (i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if ((*tetri)[i][j] == '#')
				value = value + base;
			base = base * 2;
		}
		i++;
	}
	if (!(tetri_validator(value)))
		return (-1);
	*val = value;
	return (1);
}

int			tetrireadfromfile(int fd, char ***tetri, int readn)
{
	int		i;

	i = 1;
	while (i < 4)
	{
		readn = get_next_line(fd, &((*tetri)[i]));
		if (readn != 1)
		{
			ft_free2darray(tetri, i);
			return (-1);
		}
		i++;
	}
	return (1);
}

int			check_new_line(int fd, char **line, t_tetrimino **lst, int tetri)
{
	tetri = get_next_line(fd, line);
	if (tetri == 1 && ((ft_strcmp(*line, "") == 0 && *lst == NULL) || \
				(ft_strcmp(*line, "") != 0 && *lst != NULL)))
	{
		free(*line);
		return (-1);
	}
	if (tetri == 0)
	{
		if (*lst != NULL)
			return (0);
		else
			return (-1);
	}
	if (ft_strcmp(*line, "") == 0)
	{
		free(*line);
		tetri = get_next_line(fd, line);
		if (tetri != 1)
			return (-1);
	}
	return (1);
}

t_tetrimino	*get_tetrimino(int fd, t_tetrimino **lst, int *status)
{
	unsigned short	val;
	t_tetrimino		*new_tetri;
	char			**tetrimin;
	char			*line;

	*status = 0;
	*status = check_new_line(fd, &line, lst, *status);
	if (*status != 1)
		return (NULL);
	tetrimin = (char **)malloc(sizeof(char *) * 4);
	tetrimin[0] = line;
	*status = tetrireadfromfile(fd, &tetrimin, *status);
	if (*status == -1 || *status == 0)
		return (NULL);
	*status = tetrivalue(&tetrimin, &val);
	if (*status != 1)
	{
		ft_free2darray(&tetrimin, 4);
		return (NULL);
	}
	new_tetri = new_tetrimino(&tetrimin, val);
	ft_free2darray(&tetrimin, 4);
	return (new_tetri);
}
