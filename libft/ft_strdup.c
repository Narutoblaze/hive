/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:26:14 by raho              #+#    #+#             */
/*   Updated: 2021/12/31 10:44:12 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		index;
	char	*newstr;

	index = 0;
	newstr = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!newstr)
		return (0);
	while (s1[index] != '\0')
	{
		newstr[index] = s1[index];
		index++;
	}
	newstr[index] = '\0';
	return (newstr);
}
