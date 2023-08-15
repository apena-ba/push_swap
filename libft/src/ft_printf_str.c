/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:57:54 by apena-ba          #+#    #+#             */
/*   Updated: 2022/05/19 19:10:43 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_str(char *str, size_t *cont)
{
	size_t	pos;

	pos = 0;
	if (!str)
	{
		ft_printf_str("(null)", cont);
	}
	else
	{
		while (str[pos])
		{
			ft_escribir(str[pos], cont);
			pos++;
		}
	}
}
