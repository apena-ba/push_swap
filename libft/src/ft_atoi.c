/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 21:14:35 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/02 20:26:29 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	int		pos;
	long	res;
	int		men;

	pos = 0;
	men = 1;
	res = 0;
	while ((str[pos] >= 9 && str[pos] <= 13) || str[pos] == ' ')
		pos++;
	if (str[pos] == '-' || str[pos] == '+')
	{
		if (str[pos] == '-')
			men = -1;
		pos++;
	}
	while (str[pos] >= '0' && str[pos] <= '9')
	{
		res = res * 10;
		res = res + (str[pos] - 48);
		pos++;
	}
	return (res * men);
}
