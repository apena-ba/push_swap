/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:09:15 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/11 16:33:18 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_ab(int *stack1, int *stack2, t_data *info)
{
	rotate_a(stack1, info, 2);
	rotate_b(stack2, info, 2);
	ft_printf("rr\n");
}

void	reverse_rotate_ab(int *stack1, int *stack2, t_data *info)
{
	reverse_rotate_a(stack1, info, 2);
	reverse_rotate_b(stack2, info, 2);
	ft_printf("rrr\n");
}
