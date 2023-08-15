/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:39:51 by apena-ba          #+#    #+#             */
/*   Updated: 2022/04/27 15:00:34 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*res;
	size_t	t;
	size_t	pos;
	size_t	pos2;

	if (!str1 || !str2)
		return (NULL);
	t = ft_strlen(str1) + ft_strlen(str2);
	res = (char *)malloc(sizeof(char) * (t + 1));
	if (!res)
		return (NULL);
	res[t] = 0;
	pos = 0;
	pos2 = 0;
	while (str1[pos2] != '\0')
	{
		res[pos] = str1[pos2];
		pos++;
		pos2++;
	}
	pos2 = 0;
	while (str2[pos2] != '\0')
		res[pos++] = str2[pos2++];
	return (res);
}
