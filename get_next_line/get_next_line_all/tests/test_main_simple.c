/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 22:24:50 by raho              #+#    #+#             */
/*   Updated: 2021/12/21 08:44:33 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	fd;
	int	ret;	

	ret = 1;
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
	while ((ret = get_next_line_simple(fd)))
	{
		printf("\nreturn value: %d\n", ret);
		/* test for failing the reading */
		/*
		if (close(fd) == -1)
		{
			ft_putendl("close failed");
			return (1);
		}
		*/
	}
	printf("return value: %d\n", ret);
	if (close(fd) == -1)
	{
		ft_putendl("close failed");
		return (1);
	}
	return (0);
}
