/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:43:24 by apena-ba          #+#    #+#             */
/*   Updated: 2022/04/25 18:39:36 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	pos;

	if (!dest && !src)
		return (NULL);
	if (dest < src)
	{
		pos = 0;
		while (pos < n)
		{
			*(char *)(dest + pos) = *((char *)(src) + pos);
			pos++;
		}
	}
	else if (dest > src)
	{
		while (n--)
			*(char *)(dest + n) = *((char *)(src) + n);
	}
	return (dest);
}
