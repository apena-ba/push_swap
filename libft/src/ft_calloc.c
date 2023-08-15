/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:16:22 by apena-ba          #+#    #+#             */
/*   Updated: 2022/04/26 20:38:29 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t t)
{
	void	*array;

	if (n * t < t && n * t < n)
		return (NULL);
	array = malloc(n * t);
	if (!array)
		return (NULL);
	ft_bzero(array, t * n);
	return (array);
}
