/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 21:04:48 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/11 16:31:52 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_n_close_a(int n, int *stack1, t_data *info)
{
	int	i;
	int	diff;
	int	closer;
	int	min_diff;

	i = 0;
	closer = info->size;
	min_diff = info->size;
	while (i < info->s1size)
	{
		diff = stack1[i] - n;
		if (diff > 0 && diff < min_diff)
		{
			min_diff = diff;
			closer = stack1[i];
		}
		i++;
	}
	return (closer);
}

int	close_index(int n, int *stack1, t_data *info)
{
	int	i;

	i = 0;
	while (i < info->s1size)
	{
		if (stack1[i] == n)
			return (i);
		i++;
	}
	return (-1);
}
