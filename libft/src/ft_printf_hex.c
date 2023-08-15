/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:56:30 by apena-ba          #+#    #+#             */
/*   Updated: 2022/05/04 18:46:32 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_aux(unsigned long long c, char *base, size_t *cont)
{
	if (c >= 16)
		ft_printf_aux(c / 16, base, cont);
	ft_escribir(base[c % 16], cont);
}

void	ft_printf_ptr(unsigned long long p, size_t *cont)
{
	ft_printf_str("0x", cont);
	ft_printf_aux(p, "0123456789abcdef", cont);
}

void	ft_printf_hex_num(unsigned int c, char *base, size_t *cont)
{
	if (c >= 16)
		ft_printf_hex_num(c / 16, base, cont);
	ft_escribir(base[c % 16], cont);
}
