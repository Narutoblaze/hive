/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:44:34 by raho              #+#    #+#             */
/*   Updated: 2022/02/03 23:58:07 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	round_up(float nb)
{
	return (nb + 0.999999999999999);
}

static int	sqrt(int nb)
{
	float	sqrt;
	float	temp;

	sqrt = nb / 2;
	temp = 0;
	while (sqrt != temp)
	{
		temp = sqrt;
		sqrt = (nb/temp + temp) / 2;
	}
	return (round_up(sqrt));
}

/* Creates a 2D array grid for the square. Its size is 10x10 and there will be
** 2x2 square of dots in the top-left corner of it, other places will be
** initialized to 0. In case of an error while allocating memory, the function
** calls to free all dynamically allocated memories and exits with error codes.
*/

static char	**new_square(t_tlist *head, int smallest_size)
{
	int	index;
	char	**square;

	index = 0;
	square = (char **)malloc(sizeof(char *) * 27);
	if (square == NULL)
	{
		free_list(head);
		exit (7);
	}
	while (index < 26)
	{
		square[index] = ft_memalloc(27);
		if (square[index] == NULL)
		{
			free_all(head, square);
			exit (8);
		}
		if (index < smallest_size)
			ft_memset(square[index], '.', smallest_size);
		index++;
	}
	square[index] = 0;
	return (square);
}

/* Every time the function is called, it increases the width and the
** height of the dot square inside that's inside the 2D array grid.
*/

static void	enlargen_square(char **square)
{
	static int	size;
	int		row;
	int		col;

	row = 0;
	while (row < (size + 3))
	{
		col = 0;
		if (square[row][col] == '.')
			square[row][size + 2] = '.';
		else
		{
			while (col < (size + 3))
			{
				square[row][col] = '.';
				col++;
			}
		}	
		row++;
	}
	size++;
}

/* Removes a tetrimino piece using the help of 'int letter' that was saved in 
** the structs when turning the '#'s into letters.
*/

static void	remove_piece(char **square, t_tlist *head)
{
	int	row;
	int	col;

	row = 0;
	while (square[row] != NULL)
	{
		col = 0;
		while (square[row][col] != '\0')
		{
			if (square[row][col] == head->letter)
				square[row][col] = '.';
			col++;
		}
		row++;
	}
}

/* Checks and places tetrimino piece to the given coordinate if possible.
** Returns true if succesful and false if it not.
*/

static int	place(char **square, t_tlist *elem, int row, int col)
{
	int	hrow;	// element's traversing starts from the top left corner, hence it needs its own coordinates
	int	hcol;
	int	srow;	// We have specific coordinates for the square's grid and we want to remember their starting positions
	int	scol;	// so we create new variables that we can increment
	int	counter;

	hrow = 0;
	srow = row;
	counter = 0;
	while (elem->tetrimino[hrow] != NULL)
	{
		hcol = 0;
		scol = col;
		while (elem->tetrimino[hrow][hcol] != '\0')
		{
			if (square[srow] == NULL || square[srow][scol] == '\0')
			{
				if (counter != 0)
					remove_piece(square, elem);
				return (0);
			}
			if (square[srow][scol] == '.' && elem->tetrimino[hrow][hcol] == elem->letter)
			{
				square[srow][scol] = elem->letter;
				counter++;
				if (counter == 4)
					return (1);
				if (elem->tetrimino[hrow][hcol + 1] != elem->letter)
					break;
			}
			else if ((square[srow][scol] != '.' && elem->tetrimino[hrow][hcol] == elem->letter) || square[srow][scol] == '\0')
			{
				if (counter != 0)
					remove_piece(square, elem);
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

/* Goes through the square to check if the next tetrimino can be placed in it.
** Checks every coordinate one by one with function 'place_tetrimino'.
** If tetrimino was placed and there are more tetriminos left in the list,  
** the function calls for itself with the next tetrimino as the new head of the
** list. If placing isn't possible at some point, the tetrimino is removed and
** the checking continues. If the function reaches the end of the square
** without being able to place all the tetriminos, it returns 0 so that the
** previous function knows to increase the square size for the next try.
*/
 
static int	fillit(char **square, t_tlist *head)
{
	int	col;
	int	row;

	row = 0;
	while (square[row] != NULL)	// Go through the square to check if a tetrimino can be placed in it
	{
		col = 0;
		while (square[row][col] != '\0')
		{
			if (place(square, head, row, col))  // Checks the spot and places if possible. Returns true if succesful, false if not
			{
				if (head->next->next != NULL)
				{
					if (fillit(square, head->next))  // Calls for the function again to do the rest of the pieces
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

/* Creates the square where to put all the tetrimino pieces. Its size is
** 10x10 and there will be only 2x2 square of dots inside since 2x2 is the
** smallest solved square.
** Calls the solving function 'fillit' in a while loop and every time that
** the function can't solve the square, it enlarges the square of dots.
** Prints the solved square to the standard output.
*/

void	solve_square(t_tlist *head, int count)
{
	int	index;
	char	**square;
	int	smallest_size;

	index = 0;
	count = count * 4;
	smallest_size = sqrt(count);
	square = new_square(head, smallest_size);
	while (fillit(square, head) == 0)
		enlargen_square(square);
	while (square[index] != NULL && square[index][0] != '\0')
	{
		ft_putendl(square[index]);
		index++;
	}
}
