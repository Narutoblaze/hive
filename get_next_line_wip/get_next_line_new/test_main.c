/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 11:53:03 by raho              #+#    #+#             */
/*   Updated: 2021/12/31 12:56:43 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char	*line;
	int	fd;
	int	ret;

	line = NULL;
	fd = open("Two", O_RDONLY);
	if (fd == -1)
	{
		printf("open failed\n");
		return (0);
	}
	while((ret = get_next_line(fd, &line)))
		printf("%d %s\n", ret, line);
	if (close(fd) == -1)
	{
		printf("close failed\n");
		return (0);
	}
	return (0);
}	
