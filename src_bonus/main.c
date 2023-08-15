/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:53:55 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/11 17:57:12 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	mini_validator(char *str)
{
	if (ft_strncmp(str, "ra\n", 3) == 0)
		return (1);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		return (1);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		return (1);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		return (1);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		return (1);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		return (1);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		return (1);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		return (1);
	else if (ft_strncmp(str, "sa\n", 3) == 0)
		return (1);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		return (1);
	return (0);
}

static void	ft_execute(char *str, int *stack1, int *stack2, t_data *info)
{
	if (ft_strncmp(str, "ra\n", 3) == 0)
		return (rotate_a_bonus(stack1, info));
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		return (rotate_b_bonus(stack2, info));
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		return (rotate_ab_bonus(stack1, stack2, info));
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		return (reverse_rotate_a_bonus(stack1, info));
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		return (reverse_rotate_b_bonus(stack2, info));
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		return (reverse_rotate_ab_bonus(stack1, stack2, info));
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		return (push_a_bonus(stack1, stack2, info));
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		return (push_b_bonus(stack1, stack2, info));
	else if (ft_strncmp(str, "sa\n", 3) == 0)
		return (swap_a_bonus(stack1, info));
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		return (swap_b_bonus(stack2, info));
}

static void	super_free(int *stack1, int *stack2, t_data *info)
{
	free(stack1);
	free(stack2);
	free(info->sorted);
	ft_free_charpp(info->to_validate);
}

static int	comparator_bonus(int *stack1, t_data *info)
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

int	main(int argc, char **argv)
{
	int		*stack1;
	int		*stack2;
	t_data	info;
	char	*to_execute;

	if (validator(argc, (const char **)argv, &info) == 0)
		return (write(2, "Error\n", 6), 0);
	stack1 = stack1_creator(&info);
	stack2 = stack2_creator(&info);
	stack_sorter(stack1, &info);
	to_execute = malloc(sizeof(char) * 5);
	ft_strcpy(to_execute, get_next_line(0));
	while (*to_execute)
	{
		if ((mini_validator(to_execute)) == 0)
			return (write(2, "Error\n", 6));
		ft_execute(to_execute, stack1, stack2, &info);
		ft_strcpy(to_execute, get_next_line(0));
	}
	if (comparator_bonus(stack1, &info) == 0)
		return (write(1, "KO\n", 3));
	write(1, "OK\n", 3);
	super_free(stack1, stack2, &info);
}
