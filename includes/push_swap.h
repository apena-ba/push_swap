/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 19:35:29 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/11 22:30:46 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	int		size;
	int		s1size;
	int		s2size;
	int		close;
	int		index;
	int		chunk_point;
	char	**to_validate;
	int		*sorted;
	int		*cal_tab;
}			t_data;

int			validator(int argc, const char **argv, t_data *info);

char		**to_validate_creator(int argc, const char **argv);

int			ft_free_to_validate(char **to_validate);

int			*stack1_creator(t_data *info);

int			*stack2_creator(t_data *info);

void		ft_print_stacks(int *stack1, int *stack2, t_data *info);

void		swap_a(int *stack1, t_data *info);

void		swap_b(int *stack2, t_data *info);

void		push_a(int *stack1, int *stack2, t_data *info);

void		push_b(int *stack1, int *stack2, t_data *info);

void		rotate_a(int *stack1, t_data *info, int x);

void		rotate_b(int *stack2, t_data *info, int x);

void		reverse_rotate_a(int *stack1, t_data *info, int x);

void		reverse_rotate_b(int *stack2, t_data *info, int x);

void		reverse_rotate_ab(int *stack1, int *stack2, t_data *info);

void		rotate_ab(int *stack1, int *stack2, t_data *info);

void		stack_sorter(int *stack1, t_data *info);

int			comparator(int *stack1, t_data *info);

int			mini_compare(int *stack1, t_data *info);

void		get_smallest(int x, int *stack1, int *stack2, t_data *info);

void		get_smallest_mini(int *stack1, int *stack2, t_data *info);

int			ft_biggest(int n, int *stack, t_data *info);

int			ft_smallest(int n, int *stack, t_data *info);

void		three_sort(int *stack, t_data *info);

void		four_sort(int *stack1, int *stack2, t_data *info);

void		five_sort(int *stack1, int *stack2, t_data *info);

void		hundred_sort(int *stack1, int *stack2, t_data *info);

void		super_sort(int *stack1, int *stack2, t_data *info);

void		push_half(int *stack1, int *stack2, t_data *info);

void		get_position(int *stack1, int *stack2, t_data *info);

int			single_cal(int n, int *stack1, int *stack2, t_data *info);

int			ft_small_index(int *stack1, t_data *info);

void		get_number(int n, int *stack1, int *stack2, t_data *info);

int			get_n_close_a(int n, int *stack1, t_data *info);

int			close_index(int n, int *stack1, t_data *info);

void		ft_rotation(int n, int *stack1, int *stack2, t_data *info);

void		swap_b_bonus(int *stack2, t_data *info);

void		swap_a_bonus(int *stack2, t_data *info);

void		rotate_a_bonus(int *stack1, t_data *info);

void		rotate_b_bonus(int *stack1, t_data *info);

void		reverse_rotate_a_bonus(int *stack1, t_data *info);

void		reverse_rotate_b_bonus(int *stack1, t_data *info);

void		push_a_bonus(int *stack1, int *stack2, t_data *info);

void		push_b_bonus(int *stack1, int *stack2, t_data *info);

void		rotate_ab_bonus(int *stack1, int *stack2, t_data *info);

void		reverse_rotate_ab_bonus(int *stack1, int *stack2, t_data *info);

#endif