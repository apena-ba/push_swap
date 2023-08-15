/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 21:42:30 by apena-ba          #+#    #+#             */
/*   Updated: 2022/04/26 20:16:08 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	pos;
	size_t	contador;

	pos = 0;
	contador = 0;
	while (src[contador] != '\0')
		contador++;
	if (dstsize > 0)
	{
		while (pos < (dstsize - 1) && src[pos] != '\0')
		{
			dst[pos] = src[pos];
			pos++;
		}
		dst[pos] = '\0';
	}
	return (contador);
}
