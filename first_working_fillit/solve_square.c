/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:44:34 by raho              #+#    #+#             */
/*   Updated: 2022/02/01 00:10:06 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	square_malloc(t_tetrimino *square)
{
	static int	size;
	int		index;
	char		**new;

	index = 0;
	new = (char **)malloc(sizeof(char *) * ((size + 6) + 1)); // start from 2x2
	if (!new)
		return ;
	while (index < (size + 6))
	{
		new[index] = (char *)malloc(sizeof(char) * ((size + 6) + 1));
		if (!new[index])
			return ;
		ft_memset(new[index], '.', (size + 6));
		index++;
	}
	new[index] = 0;
	/*
	if (square->line)
		free(square->line);
	*/
	square->line = new;
	square->width = (size + 6);
	square->height = (size + 6);
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

/* Removes a tetrimino piece using the help of 'int letter' that was saved when turning the '#'s into letters. */

static void	remove_piece(t_tetrimino *square, t_tetrimino *head)
{
	int	row;
	int	col;

	row = 0;
	while (square->line[row] != NULL)
	{
		col = 0;
		while (square->line[row][col] != '\0')
		{
			if (square->line[row][col] == head->letter)
				square->line[row][col] = '.';
			col++;
		}
		row++;
	}
}

/* Checks and places tetrimino piece to the given coordinate if possible. Returns true if it could place and false if it couldn't. */

static int	place(t_tetrimino *square, t_tetrimino *head, int row, int col)
{
	int	hrow;	// head's traversing starts from the top left corner, hence it needs its own coordinates
	int	hcol;
	int	srow;	// We have specific coordinates for the square's grid and we want to remember their starting positions
	int	scol;	// so we create new variables that we can increment
	int	counter;

	hrow = 0;
	srow = row;
	counter = 0;
	while (head->line[hrow] != NULL)
	{
		hcol = 0;
		scol = col;
		while (head->line[hrow][hcol] != '\0')
		{
			if (square->line[srow] == NULL || square->line[srow][scol] == '\0')
			{
				remove_piece(square, head);
				return (0);
			}
			if (square->line[srow][scol] == '.' && head->line[hrow][hcol] == head->letter)
			{
				square->line[srow][scol] = head->letter;
				counter++;
				if (counter == 4)
					return (1);
				if (head->line[hrow][hcol + 1] != head->letter)
					break;
			}
			else if ((square->line[srow][scol] != '.' && head->line[hrow][hcol] == head->letter) || square->line[srow][scol] == '\0')
			{
				remove_piece(square, head);
				return (0);
			}
			hcol++;
			scol++;
		}
		hrow++;
		srow = row + hrow;
	}
	return (1);
}

/* Solves a fixed size square recursively */
 
static int	solve(t_tetrimino *square, t_tetrimino *head)
{
	int	col;
	int	row;

	row = 0;
	while (square->line[row] != NULL)	// Go through the square to check if a tetrimino can be placed in it
	{
		col = 0;
		while (square->line[row][col] != '\0')
		{
			if (place(square, head, row, col))  // Checks the spot and places if possible. Returns true if succesful, false if not
			{
				if (head->next != NULL)
				{
					if (solve(square, head->next))  // Calls for the function again to do the rest of the pieces
						return (1);
					else
						remove_piece(square, head);   // Removes the previous piece that was placed
				}
				else
					return (1);    
			}
			col++;
		}
		row++;
	}
	return (0);	// If the piece couldn't be placed in any spot, return false.
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
	solve(square, head);
	return (square);
}
