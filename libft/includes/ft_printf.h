/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 21:31:32 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/08 17:59:37 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_escribir(int c, size_t *cont);

void	ft_printf_str(char *str, size_t *cont);

void	ft_printf_un(unsigned int nb, size_t *cont);

void	ft_printf_num(int nb, size_t *cont);

void	ft_printf_hex_num(unsigned int c, char *base, size_t *cont);

void	ft_printf_ptr(unsigned long long p, size_t *cont);

int		ft_printf(const char *str, ...);

#endif