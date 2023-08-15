/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:03:59 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/11 16:31:35 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_cal_return(int n1, int n2, t_data *info)
{
	if (n1 > info->s1size / 2 && n2 > info->s2size / 2)
	{
		n1 = info->s1size - n1 + 1;
		n2 = info->s2size - n2 + 1;
		if (n2 > n1)
			return (n2 - n1 + n2);
		else if (n1 > n2)
			return (n1 - n2 + n1);
		return (n1);
	}
	else if (n1 <= info->s1size / 2 && n2 <= info->s2size / 2)
	{
		if (n2 > n1)
			return (n2);
		return (n1);
	}
	if (n1 > info->s1size / 2)
		n1 = info->s1size - n1;
	if (n2 > info->s2size / 2)
		n2 = info->s2size - n2;
	return (n1 + n2);
}

static int	get_n_smallest(int x, int *stack1, t_data *info)
{
	int	i;

	i = ft_small_index(stack1, info);
	return (ft_cal_return(i, x, info));
}

int	single_cal(int n, int *stack1, int *stack2, t_data *info)
{
	int	i;
	int	closest;

	if (ft_biggest(stack2[n], stack1, info) == 1 || ft_smallest(stack2[n],
			stack1, info) == 1)
		return (get_n_smallest(n, stack1, info));
	closest = get_n_close_a(stack2[n], stack1, info);
	i = close_index(closest, stack1, info);
	return (ft_cal_return(i, n, info));
}
