/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:14:41 by apena-ba          #+#    #+#             */
/*   Updated: 2022/04/25 20:07:12 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_res(size_t lon, size_t len)
{
	if (lon > len)
		return (len);
	return (lon);
}

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	pos;

	pos = 0;
	if (!str)
		return (NULL);
	if (str[pos] == '\0')
		return (ft_strdup(""));
	if (start > ft_strlen(str))
		return (ft_strdup(""));
	sub_str = (char *)malloc(sizeof(char) * (ft_res(ft_strlen(str), len) + 1));
	if (!sub_str)
		return (NULL);
	while (pos < ft_res(ft_strlen(str), len))
	{
		sub_str[pos] = str[start + pos];
		pos++;
	}
	sub_str[pos] = 0;
	return (sub_str);
}
