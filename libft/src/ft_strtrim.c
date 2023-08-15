/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:01:56 by apena-ba          #+#    #+#             */
/*   Updated: 2022/04/25 17:25:22 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char c, const char *set)
{
	size_t	pos;

	pos = 0;
	while (set[pos])
	{
		if (set[pos] == c)
			return (1);
		pos++;
	}
	return (0);
}

char	*ft_strtrim(const char *str, const char *set)
{
	char	*str_set;
	size_t	pos;
	size_t	start;
	size_t	end;

	if (!str || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(str);
	pos = 0;
	while (str[start] && ft_check(str[start], set) == 1)
		start++;
	while (end > start && ft_check(str[end - 1], set))
		end--;
	str_set = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!str_set)
		return (NULL);
	str_set[end - start] = '\0';
	while (start < end)
	{
		str_set[pos] = str[start];
		pos++;
		start++;
	}
	return (str_set);
}
