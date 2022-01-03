/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main_argc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 22:24:50 by raho              #+#    #+#             */
/*   Updated: 2021/12/29 15:40:28 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	fd;
	int	ret;	
	char	*line;

	ret = 1;
	line = 0;
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
	{	printf("bad file name\n");
		return (0);
	}
	if (fd == -1)
	{
		ft_putendl("open failed");
		return (1);
	}
	while (ret)
	{
		ret = get_next_line(fd, &line);
		printf("%d%s", ret, line);
	}
	/* put this inside while loop for failing the reading*/
	if (close(fd) == -1)
	{
		printf("close failed");
		return (1);
	}
	return (0);
}
