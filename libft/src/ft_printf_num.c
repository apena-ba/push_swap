/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:17:14 by apena-ba          #+#    #+#             */
/*   Updated: 2022/05/04 18:23:52 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_num(int nb, size_t *cont)
{
	if (nb == -2147483648)
	{
		ft_escribir('-', cont);
		ft_escribir('2', cont);
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_escribir('-', cont);
		nb *= -1;
	}
	if (nb < 10)
	{
		ft_escribir(nb + 48, cont);
	}
	else
	{
		ft_printf_num(nb / 10, cont);
		ft_printf_num(nb % 10, cont);
	}
}

void	ft_printf_un(unsigned int nb, size_t *cont)
{
	if (nb < 10)
	{
		ft_escribir(nb + 48, cont);
	}
	else
	{
		ft_printf_un(nb / 10, cont);
		ft_printf_un(nb % 10, cont);
	}
}
