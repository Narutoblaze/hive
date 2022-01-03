/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_simple.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 03:59:27 by raho              #+#    #+#             */
/*   Updated: 2021/12/21 08:42:25 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_putstreol(int fd, char *s, int bytes_read)
{
	int		index;
	static int	offset = 0;
	
	index = 0;
	while (s[index] != '\0' && s[index] != '\n')
	{
		ft_putchar(s[index]);
		index++;
	}
	if (s[index] == '\n')
	{
		offset = offset + index + 1;
		if (lseek(fd, offset, SEEK_SET) == -1)
			return (-1);
		return (0);
	}
	offset = offset + bytes_read;
	return (1);
}

int	get_next_line_simple(const int fd)
{
	int	ret;
	char	buf[BUFF_SIZE + 1];
	int	eol;

	eol = 1;
	while (eol)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		if (ret == 0)
			return (0);
		buf[ret] = '\0';
		eol = ft_putstreol(fd, buf, ret);
	}
	if (eol == -1)
		return (-1);
	return (1);
}
