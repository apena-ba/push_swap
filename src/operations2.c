/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:58:57 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/11 16:33:13 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(int *stack1, t_data *info, int x)
{
	int	pos;
	int	aux;

	pos = 0;
	aux = stack1[0];
	while (pos < info->s1size)
	{
		stack1[pos] = stack1[pos + 1];
		pos++;
	}
	stack1[info->s1size - 1] = aux;
	if (x == 1)
		ft_printf("ra\n");
}

void	rotate_b(int *stack2, t_data *info, int x)
{
	int	pos;
	int	aux;

	pos = 0;
	aux = stack2[0];
	while (pos < (info->size - info->s1size))
	{
		stack2[pos] = stack2[pos + 1];
		pos++;
	}
	stack2[info->size - info->s1size - 1] = aux;
	if (x == 1)
		ft_printf("rb\n");
}

void	reverse_rotate_a(int *stack1, t_data *info, int x)
{
	int	pos;
	int	aux;

	pos = info->s1size;
	aux = stack1[pos - 1];
	while (pos > 0)
	{
		stack1[pos] = stack1[pos - 1];
		pos--;
	}
	stack1[0] = aux;
	stack1[info->s1size] = 0;
	if (x == 1)
		ft_printf("rra\n");
}

void	reverse_rotate_b(int *stack2, t_data *info, int x)
{
	int	pos;
	int	aux;

	pos = (info->size - info->s1size);
	aux = stack2[pos - 1];
	while (pos > 0)
	{
		stack2[pos] = stack2[pos - 1];
		pos--;
	}
	stack2[0] = aux;
	stack2[info->size - info->s1size] = 0;
	if (x == 1)
		ft_printf("rrb\n");
}
