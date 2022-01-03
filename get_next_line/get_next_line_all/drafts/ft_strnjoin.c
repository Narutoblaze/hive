/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:05:07 by raho              #+#    #+#             */
/*   Updated: 2021/12/29 15:16:14 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*append(char const *s1, char const *s2, size_t n, char *new)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (j < n && s2[j] != '\0')
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*new;
	size_t	s2len;

	if (s1 && s2 && n)
	{
		s2len = ft_strlen(s2);
		if (s2len < n)
			new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + \
								s2len) + 1);
		else
			new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + \
								n) + 1);
		if (!new)
			return (0);
		return (append(s1, s2, n, new));
	}
	return (0);
}
