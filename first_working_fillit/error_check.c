/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 22:44:32 by raho              #+#    #+#             */
/*   Updated: 2022/01/26 11:52:44 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int  side_by_side(t_tetrimino *tetrimino, int row, int col)
{
    size_t found_width;
    size_t found_height;

    found_width = 0;
    found_height = 0;
    if (col != 0)
        if (tetrimino->line[row][(col - 1)] == '#')
            found_width++;
    if (row != 0)
        if (tetrimino->line[(row - 1)][col] == '#')
            found_height++;
    if (tetrimino->line[row][(col + 1)] == '#')
        found_width++;
    if (row != 3)
        if (tetrimino->line[(row + 1)][col] == '#')
            found_height++;
    tetrimino->width = found_width + tetrimino->width;
    tetrimino->height = found_height + tetrimino->height;
    return (found_width + found_height);
}

int is_tetrimino_valid(t_tetrimino *tetrimino)
{
    size_t  count;
    size_t  len;
    int     col;
    int     row;
    int     hasfound;

    row = 0;
    hasfound = 0;
    len = 0;
    count = 0;
    while (tetrimino->line[row])
    {
        col = 0;
        while (tetrimino->line[row][col])
        {
            if (tetrimino->line[row][col++] == '#')
            {
                count++;
                hasfound = side_by_side(tetrimino, row, col - 1) + hasfound;
            }
            else if (tetrimino->line[row][col - 1] != '.')
                return (0);
            len++;
        }
        row++;
    }
    if (hasfound >= 6 && len == 16 && count == 4)
        return (1);
    return (0);
}

int  error_check(t_tetrimino *tetrimino, int gnl)
{
    while (tetrimino->next)
    {
        tetrimino->width = 0;
        tetrimino->height = 0;
        if (gnl == -2)
        {
            ft_putendl("Error tetrimino not a valid size.");
            return (0);
        }
        if (is_tetrimino_valid(tetrimino) == 0)
        {
            ft_putendl("Error tetrimino not valid.");
            return (0);
        }
        if (tetrimino->width == 4 && tetrimino->height == 4)
        {
            tetrimino->width = 2;
            tetrimino->height = 2;
        }
        if (tetrimino->width == 0)
            tetrimino->width = 1;
        if (tetrimino->height == 0)
            tetrimino->height = 1;
        if (tetrimino->width >= 4)
            if(tetrimino->width-- == 6)
                tetrimino->width--;
        if (tetrimino->height >= 4)
            if(tetrimino->height-- == 6)
                tetrimino->height--;
        tetrimino = tetrimino->next;
    }
    return (1);
}
