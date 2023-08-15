/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:43:59 by apena-ba          #+#    #+#             */
/*   Updated: 2022/04/25 16:57:19 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char const *s1, char const *s2, size_t n)
{
	size_t	pos;

	pos = 0;
	while ((s1[pos] != '\0' || s2[pos] != '\0') && n > pos)
	{
		if ((unsigned char)s1[pos] > (unsigned char)s2[pos])
		{
			return (1);
		}
		else if ((unsigned char)s1[pos] < (unsigned char)s2[pos])
		{
			return (-1);
		}
		pos++;
	}
	return (0);
}
