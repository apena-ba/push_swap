/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 14:01:34 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/11 17:07:08 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	if (!src)
	{
		*dest = 0;
		return ;
	}
	while (i < ft_strlen(src))
	{
		dest[i] = src[i];
		i++;
	}
}
