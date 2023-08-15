/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:30:58 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/13 11:28:56 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(int *stack1, t_data *info)
{
	if (mini_compare(stack1, info) == 0)
	{
		if (stack1[0] > stack1[1] && stack1[0] > stack1[2]
			&& stack1[1] < stack1[2])
			rotate_a(stack1, info, 1);
		else if (stack1[0] > stack1[1] && stack1[0] > stack1[2]
			&& stack1[1] > stack1[2])
		{
			swap_a(stack1, info);
			reverse_rotate_a(stack1, info, 1);
		}
		else if (stack1[0] < stack1[1] && stack1[0] < stack1[2])
		{
			swap_a(stack1, info);
			rotate_a(stack1, info, 1);
		}
		else if (stack1[0] > stack1[1])
			swap_a(stack1, info);
		else
			reverse_rotate_a(stack1, info, 1);
	}
}

void	four_sort(int *stack1, int *stack2, t_data *info)
{
	if (comparator(stack1, info) == 0)
	{
		get_smallest_mini(stack1, stack2, info);
		push_b(stack1, stack2, info);
		three_sort(stack1, info);
		push_a(stack1, stack2, info);
	}
}

void	five_sort(int *stack1, int *stack2, t_data *info)
{
	if (comparator(stack1, info) == 0)
	{
		get_smallest_mini(stack1, stack2, info);
		push_b(stack1, stack2, info);
		four_sort(stack1, stack2, info);
		push_a(stack1, stack2, info);
	}
}

void	hundred_sort(int *stack1, int *stack2, t_data *info)
{
	if (comparator(stack1, info) == 0)
	{
		info->cal_tab = malloc(sizeof(int) * info->size);
		ft_bzero(info->cal_tab, info->size);
		while (info->s1size > 3)
			push_b(stack1, stack2, info);
		three_sort(stack1, info);
		while (info->s1size < info->size)
		{
			get_position(stack1, stack2, info);
			push_a(stack1, stack2, info);
		}
	}
	while (comparator(stack1, info) == 0)
	{
		if (ft_small_index(stack1, info) > info->s1size / 2)
			reverse_rotate_a(stack1, info, 1);
		else
			rotate_a(stack1, info, 1);
	}
}

void	super_sort(int *stack1, int *stack2, t_data *info)
{
	if (comparator(stack1, info) == 0)
	{
		info->cal_tab = malloc(sizeof(int) * info->size);
		ft_bzero(info->cal_tab, info->size);
		push_half(stack1, stack2, info);
		while (info->s1size > 3)
			push_b(stack1, stack2, info);
		three_sort(stack1, info);
		while (info->s1size < info->size)
		{
			get_position(stack1, stack2, info);
			push_a(stack1, stack2, info);
		}
	}
	while (comparator(stack1, info) == 0)
	{
		if (ft_small_index(stack1, info) > info->s1size / 2)
			reverse_rotate_a(stack1, info, 1);
		else
			rotate_a(stack1, info, 1);
	}
}
