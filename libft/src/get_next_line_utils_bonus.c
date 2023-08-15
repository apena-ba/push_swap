/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:22:52 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/11 16:57:53 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen_gnl(const char *str)
{
	int	con;

	con = 0;
	while (str[con] != '\0')
		con++;
	return (con);
}

char	*ft_strjoin_gnl(char *str1, char *str2)
{
	char	*res;
	int		pos;
	int		pos2;

	if (!str1 || !str2)
		return (NULL);
	res = malloc(sizeof(char)
			* (ft_strlen_gnl(str1) + ft_strlen_gnl(str2) + 1));
	if (!res)
		return (NULL);
	pos = 0;
	while (str1[pos] != '\0')
	{
		res[pos] = str1[pos];
		pos++;
	}
	pos2 = 0;
	while (str2[pos2] != '\0')
		res[pos++] = str2[pos2++];
	res[pos] = '\0';
	free(str1);
	return (res);
}

char	*ft_strchr_gnl(const char *str, int c)
{
	int	pos;

	pos = 0;
	if (!str)
		return (NULL);
	while (str[pos] != '\0')
	{
		if (str[pos] == (char)c)
			return ((char *)(str + pos));
		pos++;
	}
	if (str[pos] == (char)c)
		return ((char *)(str + pos));
	return (NULL);
}
