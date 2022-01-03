/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:36:41 by raho              #+#    #+#             */
/*   Updated: 2021/12/20 22:39:31 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		h;
	int		i;
	char	*ret;

	h = 0;
	i = 0;
	if (s2[i] == '\0')
		return ((char *)s1);
	while (n > 0 && s1[h] != '\0')
	{
		i = 0;
		while ((n - 1) > 0 && s1[h + i] != '\0' && s1[h + i] == s2[i])
		{
			if (i == 0)
				ret = (char *)&s1[h];
			i++;
		}
		if (s2[i] == '\0')
			return (ret);
		h++;
		n--;
	}
	return (0);
}
