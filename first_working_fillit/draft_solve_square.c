/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:44:34 by raho              #+#    #+#             */
/*   Updated: 2022/01/27 23:31:30 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int g_y = 0;
int g_x = 0;

static void	square_malloc(t_tetrimino *square)
{
	static int	size;
	int		index;
	char		**new;

	index = 0;
	new = (char **)malloc(sizeof(char *) * ((size + 2) + 1)); // start from 2x2
	if (!new)
		return ;
	while (index < (size + 2))
	{
		new[index] = (char *)malloc(sizeof(char) * ((size + 2) + 1));
		if (!new[index])
			return ;
		ft_memset(new[index], '.', (size + 2));
		index++;
	}
	new[index] = 0;
	if (square->line)
		free(square->line);
	square->line = new;
	square->width = (size + 2);
	square->height = (size + 2);
	size++;
}

static void	move_up(t_tetrimino *head)
{
	int	x;
	int	y;

	y = 0;
	while (head->line[y + 1])
	{
		x = 0;
		while (head->line[y][x])
		{
			head->line[y][x] = head->line[y + 1][x];
			x++;
		}
		y++;
	}
	x = 0;
	while (head->line[y][x])
	{
		head->line[y][x] = '.';
		x++;
	}
}

static void	move_left(t_tetrimino *head)
{
	int	x;
	int	y;

	y = 0;
	while (head->line[y])
	{
		x = 0;
		while (head->line[y][x + 1])
		{
			head->line[y][x] = head->line[y][x + 1];
			x++;
		}
		head->line[y][x] = '.';
		y++;
	}
}

static void	move_tetrimino(t_tetrimino *head)
{
	t_tetrimino	*temp;
	int		x;
	int		y;
	int		cx;
	int		cy;

	temp = head;
	while (temp->next)
	{
		y = 0;
		cy = 0;
		while (temp->line[y])
		{
			x = 0;
			cx = 0;
			while (y < 3 && temp->line[y][x])
			{
				
				if (temp->line[y][x] == '.')
					cx++;
				x++;
			}
			if (cx == 4 && cy == 0)
				move_up(temp);
			else if (temp->line[y][0] == '.')
			{
				cy++;
				y++;
			}
			else
				break;
		}
		if (cy == 4)
			move_left(temp);
		else
			temp = temp->next;
	}
}

static void	make_alpha(t_tetrimino *head)
{
	int		index;
	int		x;
	int		y;
	t_tetrimino	*temp;

	index = 65;
	temp = head;
	while (temp->next)
	{
		y = 0;
		while(temp->line[y])
		{
			x = 0;
			while (temp->line[y][x])
			{
				if (temp->line[y][x] == '#')
					temp->line[y][x] = index;
				x++;
			}
			y++;
		}
		temp->letter = index;
		temp = temp->next;
		index++;
	}
}



static int	place_tetrimino(t_tetrimino *square, t_tetrimino *head)
{
	int	x;
	int	y;
	int	sx;
	int	sy;

	sy = 0;
	sx = 0;
	while (square->line[sy][sx] != '.')
	{
		sx++;
		if (!square->line[sy][sx])		
		{
			if (square->line[sy + 1])
			{
				sy++;
				sx = 0;
			}
			else
				return (0);
		}
	}
	y = 0;
	while (y < head->height)
	{
		x = 0;
		if (!square->line[sy])
			return (0);
		while (x < head->width)
		{
			if (!square->line[sy][sx])
				return (0);
			if (head->line[y][x] == head->letter)
				square->line[sy][sx] = head->line[y][x];
			x++;
			sx++;
		}
		y++;
		sy++;
		sx = sx - head->width;
	}
	return (1);
}

static void	solving_loop(t_tetrimino *square, t_tetrimino *head)
{
	t_tetrimino	*temp;

	temp = head;
	while (temp->next)
	{
		if (place_tetrimino(square, temp) == 0)
		{
			square_malloc(square);
			temp = head;
		}
		else
			temp = temp->next;
	}
}

t_tetrimino	*solve_square(t_tetrimino *head)
{
	t_tetrimino	*square;

	square = (t_tetrimino *)malloc(sizeof(t_tetrimino));
	if (!square)
		return 0;
	square_malloc(square);
	move_tetrimino(head);
	make_alpha(head);
	solving_loop(square, head);
	return (square);
}
