/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:51:19 by raho              #+#    #+#             */
/*   Updated: 2021/12/30 09:45:41 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strclen(const char *s, int c)
{
	size_t	index;

	index = 0;
	while (s[index] != '\n' && s[index] != '\0')
		index++;
	if (s[index] == (char)c)
		return (index + 1);
	return (0);
}
