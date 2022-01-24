/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:43:36 by raho              #+#    #+#             */
/*   Updated: 2022/01/24 17:31:38 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*	To check if the tetriminos were correctly saved as 2D arrays.	*/

static void	print_tetriminos(int nb, char ***tetrimino)
{
	int	x;
	int	y;

	x = -1;
	while (x < nb)
	{
		y = 0;
		while (y < 4)
		{
			ft_putendl(tetrimino[x + 1][y]);
			y++;
		}
		x++;
		if (x < nb)
			ft_putchar('\n');
	}
}

/*	Tetriminos are 4 by 4 so static index is for 4 loops. In the beginning of every loop,	*/
/*	allocate memory for the 2D array. Each function call saves the next row to the array.	*/

static void	make2d(char ***tetrimino, char *line)
{
	static int	index;
	int		j;

	j = 0;
	if (index == 4)
		index = 0;
	if (index == 0)
	{
		*tetrimino = (char **)malloc(sizeof(char *) * 4);
		while (j < 4)
		{
			(*tetrimino)[j] = (char *)malloc(sizeof(char) * 4 + 1);
			j++;
		}
	}
	ft_strcpy((*tetrimino)[index], line);
	index++;
}

/*	Declaring double pointer to array of size 26 which is the max tetrimino count.		*/
/*	Then send the tetriminos one line at a time to "make2d" to make them into 2D arrays.	*/
/*	print_tetriminos is just to check if the 2D creation worked.				*/

static void	copy(int fd)
{
	int		index;
	int		ret;
	static char	**tetrimino[26];
	char		*line;

	index = 0;
	ret = get_next_line(fd, &line);
	while (ret)
	{
		if (*line)
			make2d(&(tetrimino)[index], line);
		else
			index++;
		free(line);
		ret = get_next_line(fd, &line);
	}
	print_tetriminos(index, tetrimino);
}

/*	open the file and send it to "copy" function	*/

void	fillit(char *filename)
{
	int	fd;
	int	index;

	index = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("error");
		return ;
	}
	copy(fd);
	if (close(fd) == -1)
	{
		ft_putendl("error");
		return ;
	}
}
