/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:25:00 by aelphias          #+#    #+#             */
/*   Updated: 2019/10/28 20:57:22 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check(char **line, int fd, char **left)
{
	char *pos;
	char *tmp;

	if (!(pos = ft_strchr(left[fd], '\n')))
		return (0);
	tmp = left[fd];
	*pos = '\0';
	*line = ft_strdup(tmp);
	pos++;
	if (*pos == '\0')
	{
		ft_strdel(&left[fd]);
		return (1);
	}
	left[fd] = ft_strdup(pos);
	ft_strdel(&tmp);
	return (1);
}

int	ft_read_line(char **line, int fd, char **left)
{
	int			ret;
	char		b[BUFF_SIZE + 1];
	char		*tmp;

	while ((ret = read(fd, b, BUFF_SIZE)))
	{
		b[ret] = '\0';
		if (!left[fd])
			left[fd] = ft_strdup(b);
		else
		{
			tmp = left[fd];
			left[fd] = ft_strjoin(tmp, b);
			ft_strdel(&tmp);
		}
		if (ft_check(line, fd, left))
			return (1);
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static char *left[11000];

	if (!line || fd < 0 || fd > 11000 || read(fd, NULL, 0) < 0)
		return (-1);
	if (left[fd] && ft_strchr(left[fd], '\n'))
		return (ft_check(line, fd, left));
	if (ft_read_line(line, fd, left))
		return (1);
	if (left[fd])
	{
		*line = ft_strdup(left[fd]);
		ft_strdel(&(left[fd]));
		return (1);
	}
	return (0);
}
