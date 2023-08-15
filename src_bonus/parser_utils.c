/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:44:05 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/11 17:13:08 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stacks(int *stack1, int *stack2, t_data *info)
{
	int	pos;

	pos = 0;
	ft_printf("\nStack1 = ");
	while (pos < info->size)
	{
		ft_printf("%d ", stack1[pos]);
		pos++;
	}
	ft_printf("\nStack2 = ");
	pos = 0;
	while (pos < info->size)
	{
		ft_printf("%d ", stack2[pos]);
		pos++;
	}
	ft_printf("\n");
}

static char	**new_argv_creator(int argc, const char **argv)
{
	char	**new_argv;
	int		pos1;
	size_t	len;

	new_argv = malloc(sizeof(char *) * argc - 1);
	new_argv[argc - 2] = 0;
	pos1 = 1;
	while (argv[pos1])
	{
		len = ft_strlen(argv[pos1]);
		new_argv[pos1 - 1] = malloc(sizeof(char) * len);
		if (!argv[pos1])
			return (ft_free_charpp(new_argv));
		new_argv[pos1 - 1][len - 1] = '\0';
		ft_strcpy(new_argv[pos1 - 1], argv[pos1]);
		pos1++;
	}
	return (new_argv);
}

char	**to_validate_creator(int argc, const char **argv)
{
	if (argc == 2)
		return (ft_split(argv[1], ' '));
	else
		return (new_argv_creator(argc, argv));
}

int	ft_free_to_validate(char **to_validate)
{
	int	pos;

	pos = 0;
	while (to_validate[pos])
	{
		free(to_validate[pos]);
		pos++;
	}
	free(to_validate);
	return (0);
}
