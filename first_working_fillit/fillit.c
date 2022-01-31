/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 22:41:01 by raho              #+#    #+#             */
/*   Updated: 2022/01/27 21:22:20 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tetrimino	*ft_lstnewmal(void)
{
	t_tetrimino	*list;

	list = malloc(sizeof(t_tetrimino));
	if (list == NULL)
		return (NULL);
    list->line = (char **)malloc(sizeof(char *) * 5);
    list->line[4] = NULL;
	list->next = NULL;
	return (list);
}

/*
static void	print_tetriminos(t_tetrimino *tetrimino)
{
	size_t index;

	while (tetrimino->next)
	{
        index = 0;
        //is_tetrimino_valid(tetrimino);
		while (tetrimino->line[index])
		{
			ft_putendl(tetrimino->line[index]);
			index++;
		}
        //printf("\n\nheight is %d\n\n", tetrimino->height);
        //printf("\n\nwidth is %d\n\n", tetrimino->width);
        tetrimino = tetrimino->next;
        if (tetrimino->next)
		    ft_putchar('\n');
	}
}
*/

static void	print_square(t_tetrimino *square)
{
	int	index;

	index = 0;
	while (square->line[index])
	{
		ft_putendl(square->line[index]);
		index++;
	}
}

static void copy(int fd)
{
	t_tetrimino *tetrimino;
	t_tetrimino *head;
	int gnl;
	int index;

	gnl = 1;
	index = 0;
	tetrimino = ft_lstnewmal(); // if index is 0 malloc space for next list and set a pointer when index is at 3
	head = tetrimino;
	while (gnl > 0)
	{
		gnl = get_next_line(fd, &tetrimino->line[index]);
		if (index == 3)
		{
			index = 0;
			tetrimino->next = ft_lstnewmal();
			tetrimino = tetrimino->next;
			gnl = get_next_line(fd, &(tetrimino->line[index]));
		}
		else if (!tetrimino->line[index]) // doesnt work atm
			gnl = -2;
		else
			index++;
	}
	tetrimino = head;
	if (error_check(tetrimino, gnl) == 0)
		ft_putendl("Error found. (Ending program...)");
	print_square(solve_square(head));
}

void fillit(char *filename)
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
