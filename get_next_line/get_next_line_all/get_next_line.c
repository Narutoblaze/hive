/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 03:59:27 by raho              #+#    #+#             */
/*   Updated: 2021/12/30 12:30:28 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	save(char **s, char **line)
{
	int	index;
	char	*temp;

	index = 0;
	while ((*s)[index] != '\n' && (*s)[index] != '\0')
		index++;
	if ((*s)[index] == '\n')
	{
		
		*line = ft_strsub(*s, 0, index);
		temp = ft_strdup(&((*s)[index + 1]));
		free (*s);
		*s = temp;
		if ((*s)[0] == '\0')
			ft_strdel(s);
	}
	else
	{
		*line = ft_strdup(*s);
		ft_strdel(s);
	}
	return (1);
}

static int	result(char **s, int ret, int fd, char **line)
{
	if (ret == -1)
		return (-1);
	if (ret == 0 && s[fd] == NULL)
		return (0);
	else
		return (save(&s[fd], line));
}

int	get_next_line(const int fd, char **line)
{
	int		ret;
	char		buf[BUFF_SIZE + 1];
	static char	*s[4096];
	char		*temp;

	if (fd < 0 || !line)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (!s[fd])
			s[fd] = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(s[fd], buf);
			free(s[fd]);
			s[fd] = temp;
		}
		if (ft_strchr(s[fd], '\n'))
			break;
	}
	return (result(s, ret, fd, line));
}
