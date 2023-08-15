/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:44:06 by apena-ba          #+#    #+#             */
/*   Updated: 2022/04/25 18:20:44 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	pos;

	pos = ft_strlen(str);
	while (pos >= 0)
	{
		if (str[pos] == (char)c)
			return ((char *)(str + pos));
		pos--;
	}
	return (NULL);
}
