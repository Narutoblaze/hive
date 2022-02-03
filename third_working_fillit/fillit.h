/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:44:44 by raho              #+#    #+#             */
/*   Updated: 2022/02/03 22:31:04 by raho             ###   ########.fr       */
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
void	solve_square(t_tlist *head, int count);
void	free_list(t_tlist *head);
void	free_square(char **square);
void	free_all(t_tlist *head, char **square);

#endif
