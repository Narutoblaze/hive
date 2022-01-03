/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:06:28 by raho              #+#    #+#             */
/*   Updated: 2021/11/24 23:11:00 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoaFill(int n, int count, char *new)
{
	int	singleNbr;

	new[count] = '\0';
	if (n == -2147483648)
	{
		count--;
		new[count] = 8 + 48;
		n = n / 10;
	}
	if (n < 0)
	{
		new[0] = '-';
		n = n * (-1);
	}
	if (n == 0)
		new[0] = 0 + 48;
	while (count > 0 && n != 0)
	{
		count--;
		singleNbr = n;
		new[count] = singleNbr % 10 + 48;
		n = n / 10;
	}
	return (new);
}

static int	ft_nbrLen(int n)
{
	int	calcLen;
	int	count;

	calcLen = n;
	count = 0;
	if (n == -2147483648)
		count = 11;
	else if (n == 0)
		return (1);
	else
	{
		while (calcLen != 0)
		{
			if (calcLen < 0)
			{
				calcLen = calcLen * (-1);
				count++;
			}
			calcLen = calcLen / 10;
			count++;
		}
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*new;

	len = ft_nbrLen(n);
	new = (char *)malloc(sizeof(char) * len + 1);
	if (!new)
		return (0);
	return (ft_itoaFill(n, len, new));
}
