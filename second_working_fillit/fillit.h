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

typedef struct s_tlist
{
	int					letter;
	char				**tetrimino;
	struct s_tlist	*next;
}	t_tlist;

void	handle_fd(char *file);
void	check_errors(t_tlist *head, int gnl);
void	move_tetriminos(t_tlist *head);
void	solve_square(t_tlist *head);
void	free_list(t_tlist *head);
void	free_square(char **square, int size);
void	free_all(t_tlist *head, char **square, int size);

#endif