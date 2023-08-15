/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:34:44 by apena-ba          #+#    #+#             */
/*   Updated: 2022/07/04 18:07:35 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_aux(char c, va_list va, size_t *cont)
{
	if (c == 'c')
		ft_escribir(va_arg(va, int), cont);
	else if (c == 's')
		ft_printf_str(va_arg(va, char *), cont);
	else if (c == 'p')
		ft_printf_ptr(va_arg(va, unsigned long long), cont);
	else if (c == 'd' || c == 'i')
		ft_printf_num(va_arg(va, long int), cont);
	else if (c == 'u')
		ft_printf_un(va_arg(va, unsigned int), cont);
	else if (c == 'x')
		ft_printf_hex_num(va_arg(va, unsigned int),
			"0123456789abcdef", cont);
	else if (c == 'X')
		ft_printf_hex_num(va_arg(va, unsigned int),
			"0123456789ABCDEF", cont);
	else if (c == '%')
		ft_escribir('%', cont);
}

int	ft_printf(char const *str, ...)
{
	size_t	pos;
	size_t	cont;
	va_list	va;

	va_start(va, str);
	pos = 0;
	cont = 0;
	while (str[pos])
	{
		if (str[pos] == '%')
		{
			ft_aux(str[pos + 1], va, &cont);
			pos++;
		}
		else
			ft_escribir(str[pos], &cont);
		pos++;
	}
	va_end(va);
	return (cont);
}
