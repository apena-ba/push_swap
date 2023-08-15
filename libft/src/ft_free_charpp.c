/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_charpp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:32:14 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/11 17:58:43 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free_charpp(char **to_free)
{
	int	pos;

	pos = 0;
	while (to_free[pos])
	{
		free(to_free[pos]);
		pos++;
	}
	free(to_free);
	return (NULL);
}
