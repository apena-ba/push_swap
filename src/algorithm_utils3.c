/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:06:03 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/11 16:31:30 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	mini_compare(int *stack1, t_data *info)
{
	int	i;

	i = 0;
	while (i < (info->s1size - 1))
	{
		if (stack1[i] > stack1[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static int	closest_cal(int *stack1, int *stack2, t_data *info)
{
	int	i;
	int	closer;
	int	res;

	i = 0;
	closer = info->size;
	res = -1;
	while (i < info->s2size)
	{
		info->cal_tab[i] = single_cal(i, stack1, stack2, info);
		i++;
	}
	i = 0;
	while (i < info->s2size)
	{
		if (info->cal_tab[i] < closer)
		{
			closer = info->cal_tab[i];
			res = stack2[i];
		}
		i++;
	}
	return (res);
}

void	get_position(int *stack1, int *stack2, t_data *info)
{
	int	n;

	n = closest_cal(stack1, stack2, info);
	get_number(n, stack1, stack2, info);
}
