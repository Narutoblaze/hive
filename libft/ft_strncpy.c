/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:28:51 by raho              #+#    #+#             */
/*   Updated: 2021/12/20 22:37:50 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	int	index;

	index = 0;
	while (n > 0 && s2[index] != '\0')
	{
		s1[index] = s2[index];
		index++;
		n--;
	}
	while (n > 0)
	{
		s1[index] = '\0';
		index++;
		n--;
	}
	return (s1);
}
