/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_first_working.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 03:59:27 by raho              #+#    #+#             */
/*   Updated: 2021/12/30 09:42:07 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	save(int fd, char *s, int bytes_read, char **line, int newcheck)
{
	int		index;
	static int	offset;
	char		*temp;

	index = ft_strclen(s, '\n');
	if (index)
	{
		if (!newcheck)
			*line = ft_strndup(s, (index - 1));
		else
		{
			temp = ft_strnjoin(*line, s, (index - 1));
			*line = temp;
		}
		offset = offset + index;
		if (lseek(fd, offset, SEEK_SET) == -1)
			return (-1);
		return (0);
	}
	if (!newcheck)
		*line = ft_strdup(s);
	else
	{
		temp = ft_strjoin(*line, s);
		*line = temp;
	}
	offset = offset + bytes_read;
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	int		ret;
	char		buf[BUFF_SIZE + 1];
	int		eol;
	int static	newcheck;

	eol = 1;
	if (newcheck)
	{
		free (*line);
		newcheck = 0;
	}
	while (eol)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		if (ret == 0)
			return (0);
		buf[ret] = '\0';
		eol = save(fd, buf, ret, line, newcheck);
		newcheck = 1;
	}
	if (eol == -1)
		return (-1);
	return (1);
}
