/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:43:16 by apena-ba          #+#    #+#             */
/*   Updated: 2022/04/25 18:36:32 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str, const void *str2, size_t n)
{
	size_t	pos;

	pos = 0;
	while (pos < n)
	{
		if (((unsigned char *)str)[pos] != ((unsigned char *)str2)[pos])
			return (((unsigned char *)str)[pos] - ((unsigned char *)str2)[pos]);
		pos++;
	}
	return (0);
}
