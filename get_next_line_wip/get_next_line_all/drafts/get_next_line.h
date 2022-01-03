/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 22:58:19 by raho              #+#    #+#             */
/*   Updated: 2021/12/31 10:30:56 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"

int	get_next_line_simple(const int fd);
int	get_next_line(const int fd, char **line);
size_t	ft_strclen(const char *s, int c);
char	*ft_strndup(const char *s1, size_t n);
char	*ft_strnjoin(char const *s1, char const *s2, size_t n);

#endif
