/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 22:24:50 by raho              #+#    #+#             */
/*   Updated: 2021/12/31 11:58:08 by raho             ###   ########.fr       */
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
		return (1);
	}
	if (fd == -1)
	{
		printf("open failed\n");
		return (1);
	}
	//ret = get_next_line(fd, &line);
	//printf("return value: %d\n%s\n", ret, line);
	while (ret)
	{
		ret = get_next_line(fd, &line);
		printf("%d%s", ret, line);
	}
	/* test for failing the reading (inside while loop version) */
	/*
	if (close(fd) == -1)
	{
		printf("close failed\n");
		return (1);
	}
	*/
	if (close(fd) == -1)
	{
		printf("close failed\n");
		return (1);
	}
	return (0);
}
