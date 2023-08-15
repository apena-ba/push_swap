/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:09:15 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/11 17:13:03 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_ab_bonus(int *stack1, int *stack2, t_data *info)
{
	rotate_a_bonus(stack1, info);
	rotate_b_bonus(stack2, info);
}

void	reverse_rotate_ab_bonus(int *stack1, int *stack2, t_data *info)
{
	reverse_rotate_a_bonus(stack1, info);
	reverse_rotate_b_bonus(stack2, info);
}
