/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:18:53 by apena-ba          #+#    #+#             */
/*   Updated: 2022/04/25 13:34:38 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	pos;

	pos = 0;
	str = ft_strdup(s);
	if (!str)
		return (NULL);
	while (str[pos])
	{
		str[pos] = (*f)(pos, str[pos]);
		pos++;
	}
	return (str);
}
