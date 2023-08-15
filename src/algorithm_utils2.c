/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:11:35 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/11 21:32:23 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	comparator(int *stack1, t_data *info)
{
	int	i;

	i = 0;
	while (i < info->size)
	{
		if (stack1[i] != info->sorted[i])
			return (0);
		i++;
	}
	return (1);
}

static int	stack_scanner(int *stack1, t_data *info)
{
	int	i;
	int	x;

	i = 0;
	x = info->s1size;
	while (i < info->s1size)
	{
		if (stack1[i] <= (info->size / 2))
			break ;
		i++;
	}
	while (x >= 0)
	{
		if (stack1[x] <= (info->size / 2))
			break ;
		x--;
	}
	if (stack1[0] <= (info->size / 2))
		return (0);
	if (i > (info->s1size - x))
		return (2);
	return (1);
}

static int	half_checker(int *stack1, t_data *info)
{
	int	i;

	i = 0;
	while (i < info->s1size)
	{
		if (stack1[i] <= (info->size / 2))
			return (0);
		i++;
	}
	return (1);
}

static void	get_closest(int *stack1, int *stack2, t_data *info)
{
	while (stack_scanner(stack1, info) == 1)
	{
		if (stack2[0] < stack2[1])
			rotate_ab(stack1, stack2, info);
		else
			rotate_a(stack1, info, 1);
	}
	while (stack_scanner(stack1, info) == 2)
	{
		if (stack2[0] < stack2[info->s2size - 1])
			reverse_rotate_ab(stack1, stack2, info);
		else
			reverse_rotate_a(stack1, info, 1);
	}
}

void	push_half(int *stack1, int *stack2, t_data *info)
{
	while (half_checker(stack1, info) == 0)
	{
		get_closest(stack1, stack2, info);
		push_b(stack1, stack2, info);
	}
}
