/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:11:41 by apasos-g          #+#    #+#             */
/*   Updated: 2019/03/23 21:06:39 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_line(int fd, char **gl, char **line)
{
	char	*temp;
	char	*str;

	str = ft_strdup(gl[fd]);
	free(gl[fd]);
	gl[fd] = NULL;
	if ((temp = ft_strchr(str, '\n')))
	{
		*temp = '\0';
		*line = ft_strdup(str);
		temp++;
		if (*temp != '\0')
			gl[fd] = ft_strdup(temp);
	}
	else
		*line = ft_strdup(str);
	free(str);
	str = NULL;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*gl[FILES_LIM];
	char			buff[BUFF_SIZE + 1];
	char			*temp;
	int				rnum;
	char			v;

	if (line == NULL || fd < 0 || read(fd, buff, 0))
		return (-1);
	while ((rnum = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[rnum] = '\0';
		if (gl[fd] == NULL)
			gl[fd] = ft_strnew(1);
		temp = ft_strjoin(gl[fd], buff);
		v = buff[0];
		free(gl[fd]);
		gl[fd] = temp;
		if (BUFF_SIZE == 1 && v != '\n')
			continue ;
		if (ft_strchr(gl[fd], '\n'))
			break ;
	}
	if (rnum == 0 && gl[fd] == NULL)
		return (0);
	return (get_line(fd, gl, line));
}
