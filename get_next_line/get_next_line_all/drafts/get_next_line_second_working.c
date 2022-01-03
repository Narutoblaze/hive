/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_second_working.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 03:59:27 by raho              #+#    #+#             */
/*   Updated: 2021/12/30 09:41:46 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	save_n(int index, char *s, char **line, int newcheck)
{
	char	*temp;

	index = index - 1;
	if (!newcheck)
		*line = ft_strndup(s, (size_t)index);
	else
	{
		temp = ft_strnjoin(*line, s, (size_t)index);
		free(*line);
		*line = temp;
	}
}

static void	save(char *s, char **line, int newcheck)
{
	char	*temp;

	if (!newcheck)
		*line = ft_strdup(s);
	else
	{
		temp = ft_strjoin(*line, s);
		free(*line);
		*line = temp;
	}
}

static int	search(int fd, char *s, int bytes_read, char **line, int newcheck)
{
	int		index;
	static int	offset;

	index = ft_strclen(s, '\n');
	if (index)
	{
		if (index > 1)
			save_n(index, s, line, newcheck);
		offset = offset + index;
		if (lseek(fd, offset, SEEK_SET) == -1)
			return (-1);
		return (0);
	}
	save(s, line, newcheck);
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
		eol = search(fd, buf, ret, line, newcheck);
		newcheck = 1;
	}
	if (eol == -1)
		return (-1);
	return (1);
}
