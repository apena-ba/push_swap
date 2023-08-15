/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:04:32 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/11 16:35:49 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_sorter(int *stack1, t_data *info)
{
	int	i;
	int	aux;

	i = 0;
	info->sorted = malloc(sizeof(int) * info->size);
	while (i < info->size)
	{
		info->sorted[i] = stack1[i];
		i++;
	}
	i = 0;
	while (i < info->size - 1)
	{
		if (info->sorted[i] > info->sorted[i + 1])
		{
			aux = info->sorted[i];
			info->sorted[i] = info->sorted[i + 1];
			info->sorted[i + 1] = aux;
			i = 0;
		}
		else
			i++;
	}
}

static int	ft_index(char *num, t_data *info)
{
	int	pos;
	int	cont;

	pos = 0;
	cont = 0;
	while (info->to_validate[pos])
	{
		if (ft_atoi(info->to_validate[pos]) > ft_atoi(num))
			cont++;
		pos++;
	}
	return (info->size - cont);
}

int	*stack1_creator(t_data *info)
{
	int	*stack1;
	int	i;

	i = 0;
	stack1 = malloc(sizeof(int) * info->size);
	if (!stack1)
		return (ft_free_charpp(info->to_validate));
	while (i < info->size)
	{
		stack1[i] = ft_index(info->to_validate[i], info);
		i++;
	}
	return (stack1);
}

int	*stack2_creator(t_data *info)
{
	int	*stack2;

	stack2 = malloc(sizeof(int) * info->size);
	if (!stack2)
		return (ft_free_charpp(info->to_validate));
	ft_bzero(stack2, info->size);
	return (stack2);
}
