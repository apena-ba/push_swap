/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:23:14 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/11 17:01:19 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_biggest(int n, int *stack, t_data *info)
{
	int	i;

	i = 0;
	while (i < info->s1size)
	{
		if (n < stack[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_smallest(int n, int *stack, t_data *info)
{
	int	i;

	i = 0;
	while (i < info->s1size)
	{
		if (n > stack[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_small_index(int *stack1, t_data *info)
{
	int	i;

	i = 0;
	while (i < info->s1size)
	{
		if (ft_smallest(stack1[i], stack1, info) == 1)
			break ;
		i++;
	}
	return (i);
}

void	get_smallest(int x, int *stack1, int *stack2, t_data *info)
{
	int	small;

	small = 0;
	while (small < info->s1size)
	{
		if (ft_smallest(stack1[small], stack1, info) == 1)
			break ;
		small++;
	}
	info->close = stack1[small];
	info->index = ft_small_index(stack1, info);
	ft_rotation(x, stack1, stack2, info);
}

void	get_smallest_mini(int *stack1, int *stack2, t_data *info)
{
	(void)stack2;
	while (ft_smallest(stack1[0], stack1, info) == 0)
	{
		if (ft_small_index(stack1, info) > (info->s1size / 2))
			reverse_rotate_a(stack1, info, 1);
		else
			rotate_a(stack1, info, 1);
	}
}
