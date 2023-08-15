/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:43:30 by apena-ba          #+#    #+#             */
/*   Updated: 2022/04/25 16:15:38 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *a, int c, size_t n)
{
	size_t	pos;

	pos = 0;
	while (pos < n)
	{
		*(unsigned char *)(a + pos) = (unsigned char)c;
		pos++;
	}
	return (a);
}
