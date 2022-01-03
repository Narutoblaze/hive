/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:50:12 by raho              #+#    #+#             */
/*   Updated: 2021/12/27 18:01:09 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	index;
	char	*new;

	index = 0;
	while (index < n && s[index] != '\0')
		index++;
	new = (char *)malloc(sizeof(char) * index + 1);
	if (!new)
		return (0);
	index = 0;
	while (index < n && s[index] != '\0')
	{
		new[index] = s[index];
		index++;
	}
	new[index] = '\0';
	return (new);
}

