/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 11:21:39 by raho              #+#    #+#             */
/*   Updated: 2021/12/31 13:24:42 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	save(char **str, char **line)
{
	int	index;
	char	*temp;

	index = 0;
	while ((*str)[index] != '\0' && (*str)[index] != '\n')
		index++;
	if ((*str)[index] == '\n')
	{
		*line = ft_strsub(*str, 0, index);
		temp = ft_strdup(&(*str)[index + 1]);
		free(*str);
		*str = temp;
		if (*str[0] == '\0')
		{
			free(*str);
			*str = NULL;
		}
	}
	else
	{
		*line = ft_strdup(*str);
		free(*str);
		*str = NULL;
	}
	return (1);
}

static int	result(int ret, char **str, char **line)
{
	int	index;

	index = 0;
	if (ret == -1)
		return (-1);
	if (ret == 0 && *str == NULL)
		return (0);
	return (save(str, line));
}

int	get_next_line(int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*str;
	char		*temp;
	int		ret;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if (str == NULL)
			str = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(str, buff);
			free(str);
			str = temp;
		}
		if (ft_strchr(str, '\n'))
			break;
	}
	return (result(ret, &str, line));
}
