/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:02:06 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/11 16:33:08 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(int *stack2, t_data *info)
{
	int	aux;

	if ((info->size - info->s1size) <= 1)
		return ;
	aux = stack2[0];
	stack2[0] = stack2[1];
	stack2[1] = aux;
	ft_printf("sb\n");
}

void	swap_a(int *stack1, t_data *info)
{
	int	aux;

	if (info->s1size <= 1)
		return ;
	aux = stack1[0];
	stack1[0] = stack1[1];
	stack1[1] = aux;
	ft_printf("sa\n");
}

void	push_a(int *stack1, int *stack2, t_data *info)
{
	int	i;

	if ((info->size - info->s1size) == 0)
		return ;
	i = info->s1size;
	while (i > 0)
	{
		stack1[i] = stack1[i - 1];
		i--;
	}
	stack1[0] = stack2[0];
	while (i < (info->size - info->s1size))
	{
		stack2[i] = stack2[i + 1];
		i++;
	}
	info->s1size++;
	info->s2size--;
	ft_printf("pa\n");
}

void	push_b(int *stack1, int *stack2, t_data *info)
{
	int	i;

	if (info->s1size == 0)
		return ;
	i = info->s2size;
	while (i > 0)
	{
		stack2[i] = stack2[i - 1];
		i--;
	}
	stack2[0] = stack1[0];
	while (i < info->s1size)
	{
		stack1[i] = stack1[i + 1];
		i++;
	}
	stack1[info->s1size - 1] = 0;
	info->s1size--;
	info->s2size++;
	ft_printf("pb\n");
}
