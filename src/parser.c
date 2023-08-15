/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:11:43 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/11 16:35:38 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	duplicate_counter(const char *aux, const char **to_validate)
{
	int	i;
	int	a;
	int	count;

	i = 0;
	count = 0;
	while (to_validate[i])
	{
		a = 0;
		if (ft_atoi(aux) == ft_atoi(to_validate[i]))
			count++;
		i++;
	}
	return (count);
}

static int	num_checker(const char **to_validate)
{
	int	i;
	int	a;

	i = 0;
	while (to_validate[i])
	{
		a = 0;
		while (to_validate[i][a])
		{
			if (a == 0 && to_validate[i][a] == '-')
				a++;
			if (to_validate[i][a] < 48 || to_validate[i][a] > 57)
				return (0);
			a++;
		}
		i++;
	}
	return (1);
}

static int	num_limits_checker(const char **to_validate)
{
	int	i;

	i = 0;
	while (to_validate[i])
	{
		if (ft_atoi(to_validate[i]) > 2147483647 || ft_atoi(to_validate[i])
			< -2147483648)
			return (0);
		i++;
	}
	return (1);
}

static int	num_duplicate_checker(const char **to_validate)
{
	int	i;

	i = 0;
	while (to_validate[i])
	{
		if (duplicate_counter(to_validate[i], to_validate) > 1)
			return (0);
		i++;
	}
	return (1);
}

int	validator(int argc, const char **argv, t_data *info)
{
	int	flag;

	info->to_validate = to_validate_creator(argc, argv);
	if (!info->to_validate)
		return (0);
	flag = 0;
	if (num_checker((const char **)info->to_validate) == 0)
		flag = 1;
	else if (num_limits_checker((const char **)info->to_validate) == 0)
		flag = 1;
	else if (num_duplicate_checker((const char **)info->to_validate) == 0)
		flag = 1;
	if (flag == 1)
		return (ft_free_to_validate(info->to_validate));
	info->size = 0;
	while (info->to_validate[info->size])
		info->size++;
	info->s1size = info->size;
	info->s2size = 0;
	return (1);
}
