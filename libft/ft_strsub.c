/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:03:21 by raho              #+#    #+#             */
/*   Updated: 2021/12/31 10:46:18 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	char	*newstr;

	index = 0;
	if (s)
	{
		newstr = (char *)malloc(sizeof(char) * len + 1);
		if (!newstr)
			return (0);
		while (index < len)
		{
			newstr[index] = s[start];
			index++;
			start++;
		}
		newstr[index] = '\0';
		return (newstr);
	}
	return (0);
}
