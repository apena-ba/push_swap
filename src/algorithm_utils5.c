/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:15:48 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/11 16:48:17 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_index(int n, int *stack2, t_data *info)
{
	int	i;

	i = 0;
	while (i < info->s2size)
	{
		if (stack2[i] == n)
			return (i);
		i++;
	}
	return (-1);
}

static void	mini_rotate_b(int n, int *stack1, int *stack2, t_data *info)
{
	int	i;

	i = get_index(n, stack2, info);
	if (stack1[0] != info->close)
	{
		if (info->index <= info->s1size / 2)
			rotate_a(stack1, info, 1);
		else
			reverse_rotate_a(stack1, info, 1);
	}
	if (stack2[0] != n)
	{
		if (i <= info->s2size / 2)
			rotate_b(stack2, info, 1);
		else
			reverse_rotate_b(stack2, info, 1);
	}
}

void	ft_rotation(int n, int *stack1, int *stack2, t_data *info)
{
	int	i;

	i = get_index(n, stack2, info);
	while (stack1[0] != info->close || stack2[0] != n)
	{
		if (stack1[0] != info->close && stack2[0] != n)
		{
			if (info->index <= info->s1size / 2 && i <= info->s2size / 2)
				rotate_ab(stack1, stack2, info);
			else if (info->index > info->s2size / 2 && i > info->s2size / 2)
				reverse_rotate_ab(stack1, stack2, info);
			else if (info->index <= info->s1size / 2)
				rotate_a(stack1, info, 1);
			else
				reverse_rotate_a(stack1, info, 1);
		}
		else if (stack1[0] != info->close || stack2[0] != n)
			mini_rotate_b(n, stack1, stack2, info);
	}
}

void	get_number(int n, int *stack1, int *stack2, t_data *info)
{
	if (ft_biggest(n, stack1, info) == 1 || ft_smallest(n, stack1, info) == 1)
		return (get_smallest(n, stack1, stack2, info));
	info->close = get_n_close_a(n, stack1, info);
	info->index = close_index(info->close, stack1, info);
	ft_rotation(n, stack1, stack2, info);
}
