/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:43:45 by apena-ba          #+#    #+#             */
/*   Updated: 2022/04/25 20:18:25 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	possrc;
	size_t	posdest;

	possrc = 0;
	posdest = ft_strlen(dest);
	if (size > posdest)
	{
		while (possrc < (size - posdest) - 1 && src[possrc] != '\0')
		{
			dest[posdest + possrc] = src[possrc];
			possrc++;
		}
		if (possrc <= size - posdest)
			dest[posdest + possrc] = '\0';
		return (posdest + ft_strlen(src));
	}
	return (size + ft_strlen(src));
}
