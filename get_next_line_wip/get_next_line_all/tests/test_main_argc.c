/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main_argc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 22:24:50 by raho              #+#    #+#             */
/*   Updated: 2021/12/30 12:49:49 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	fd;
	int	fd3;
	int	fd4;
	int	fd5;
	int	ret;	
	char	*line;

	ret = 1;
	line = 0;
	if (argc > 1)
	{
		if (argc == 2)
		{
			fd = open(argv[1], O_RDONLY);
			if (fd == -1)
			{
				printf("opening file %s failed\n", argv[1]);
				return (0);
			}
		}
		if (argc == 3)
		{
			fd3 = open(argv[1], O_RDONLY);
			if (fd3 == -1)
			{
				printf("opening file %s failed\n", argv[1]);
				return (0);
			}
			fd4 = open(argv[2], O_RDONLY);
			if (fd4 == -1)
			{
				printf("opening file %s failed\n", argv[2]);
				return (0);
			}
		}
		if (argc == 4)
		{
			fd3 = open(argv[1], O_RDONLY);
			if (fd3 == -1)
			{
				printf("opening file %s failed\n", argv[1]);
				return (0);
			}
			fd4 = open(argv[2], O_RDONLY);
			if (fd4 == -1)
			{
				printf("opening file %s failed\n", argv[2]);
				return (0);
			}
			fd5 = open(argv[3], O_RDONLY);
			if (fd5 == -1)
			{
				printf("opening file %s failed\n", argv[3]);
				return (0);
			}
		}
	} 
	else
	{	printf("missing or too many file names (give 1 - 3)\n");
		return (0);
	}
	while (ret)
	{
		if (fd)
		{
			ret = get_next_line(fd, &line);
			if (ret)
			{
				printf("%d %s\n", ret, line);
				free(line);
			}
		}
		if (fd3)
		{
			ret = get_next_line(fd3, &line);
			if (ret)
			{
				printf("%d %s\n", ret, line);
				free(line);
			}
		}
		if (fd4)
		{
			ret = get_next_line(fd4, &line);
			if (ret)
			{
				printf("%d %s\n", ret, line);
				free(line);
			}
		}
		if (fd5)
		{
			ret = get_next_line(fd5, &line);
			if (ret)
			{
				printf("%d %s\n", ret, line);
				free(line);
			}
		}
	}
	printf("%d\n", ret);
	/* put this inside while loop for failing the reading*/
	if (close(fd) == -1)
	{
		printf("close failed");
		return (1);
	}
	return (0);
}
