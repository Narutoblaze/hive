/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:05:07 by raho              #+#    #+#             */
/*   Updated: 2021/12/31 10:44:57 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	char	*temp;

	if (s1 && s2)
	{
		newstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + \
											ft_strlen(s2) + 1));
		if (!newstr)
			return (0);
		temp = newstr;
		while (*s1 != '\0')
			*newstr++ = *s1++;
		while (*s2 != '\0')
			*newstr++ = *s2++;
		*newstr = '\0';
		return (temp);
	}
	return (0);
}
