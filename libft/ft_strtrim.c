/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 22:00:57 by raho              #+#    #+#             */
/*   Updated: 2021/11/29 19:43:59 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlenNoWS(const char *s)
{
	int		i;
	int		lead;
	int		trail;
	size_t	len;

	i = 0;
	len = 0;
	trail = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	lead = i;
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
		{
			i++;
			trail = i;
		}
		else
			i++;
	}
	if (trail != 0)
		return (trail - lead);
	return (0);
}

static char	*ft_strcpyNoWS(char const *s, char *new)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	j = 0;
	max = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
			max = i;
		i++;
	}
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[i] != '\0' && i <= max)
	{
		new[j] = s[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}

char	*ft_strtrim(char const *s)
{
	char	*new;

	if (s)
	{
		new = (char *)malloc(sizeof(char) * (ft_strlenNoWS(s) + 1));
		if (!new)
			return (0);
		return (ft_strcpyNoWS(s, new));
	}
	return (0);
}
