/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:43:40 by apena-ba          #+#    #+#             */
/*   Updated: 2022/04/25 19:42:15 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*str2;
	size_t	pos;

	str2 = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!str || !str2)
		return (NULL);
	str2[ft_strlen(str)] = '\0';
	pos = 0;
	while (str[pos] != '\0')
	{
		str2[pos] = str[pos];
		pos++;
	}
	str2[pos] = str[pos];
	return (str2);
}
