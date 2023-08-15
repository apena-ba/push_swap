/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:43:12 by apena-ba          #+#    #+#             */
/*   Updated: 2022/04/25 16:29:47 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	pos;

	pos = 0;
	while (pos < n)
	{
		if (*(unsigned char *)(str + pos) == (unsigned char)c)
			return ((void *)(str + pos));
		pos++;
	}
	return (NULL);
}
