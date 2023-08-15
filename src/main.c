/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:09:55 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/13 18:12:05 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	super_free(int *stack1, int *stack2, t_data *info)
{
	free(stack1);
	free(stack2);
	free(info->sorted);
	free(info->cal_tab);
	ft_free_charpp(info->to_validate);
}

static void	algorithm(int *stack1, int *stack2, t_data *info)
{
	if (comparator(stack1, info) == 0)
	{
		if (info->size < 3)
			rotate_a(stack1, info, 1);
		else if (info->size == 3)
			three_sort(stack1, info);
		else if (info->size == 4)
			four_sort(stack1, stack2, info);
		else if (info->size == 5)
			five_sort(stack1, stack2, info);
		else if (info->size == 100)
			hundred_sort(stack1, stack2, info);
		else
			super_sort(stack1, stack2, info);
	}
}

int	main(int argc, char **argv)
{
	int		*stack1;
	int		*stack2;
	t_data	info;

	if (validator(argc, (const char **)argv, &info) == 0)
		return (write(2, "Error\n", 6), 0);
	stack1 = stack1_creator(&info);
	stack2 = stack2_creator(&info);
	if (!stack1 || !stack2)
		return (0);
	stack_sorter(stack1, &info);
	algorithm(stack1, stack2, &info);
	super_free(stack1, stack2, &info);
}
