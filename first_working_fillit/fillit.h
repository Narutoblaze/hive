/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:44:44 by raho              #+#    #+#             */
/*   Updated: 2022/01/26 14:00:56 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "./libft/libft.h"
# include <stdio.h>

typedef struct s_tetrimino
{
	int			height;
	int			width;
	int			letter;
	char			**line;
	struct s_tetrimino	*next;
}					t_tetrimino;

void	fillit(char *str);

int  error_check(t_tetrimino *tetrimino, int gnl);

int is_tetrimino_valid(t_tetrimino *tetrimino);

t_tetrimino	*solve_square(t_tetrimino *head);

#endif
