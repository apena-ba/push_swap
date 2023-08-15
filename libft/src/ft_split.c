/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:20:40 by apena-ba          #+#    #+#             */
/*   Updated: 2022/05/03 18:02:54 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **res, size_t pos)
{
	if (pos == 0)
	{
		free(res);
		return (NULL);
	}
	while (pos != 0)
	{
		free(res[pos]);
		pos--;
	}
	free(res[pos]);
	free(res);
	return (NULL);
}

static char	*ft_action(char const *str, size_t first, size_t last)
{
	char	*word;
	size_t	pos;

	pos = 0;
	word = malloc(sizeof(char) * (last - first) + 1);
	if (!word)
		return (NULL);
	word[last - first] = 0;
	while (first < last)
	{
		word[pos] = str[first];
		pos++;
		first++;
	}
	return (word);
}

static void	ft_nextword(char const *str, size_t *first, size_t *last, char c)
{
	*first = *last;
	while (str[*first] == c)
		*first = *first + 1;
	*last = *first;
	while (str[*last] != c && str[*last] != '\0')
		*last = *last + 1;
}

static size_t	ft_np(char const *str, char c)
{
	size_t	count;
	size_t	first;
	size_t	last;

	count = 0;
	first = 0;
	last = 0;
	while (str[last] != '\0')
	{
		ft_nextword(str, &first, &last, c);
		if (last == first)
			break ;
		else
			count++;
	}
	return (count);
}

char	**ft_split(char const *str, char c)
{
	char	**res;
	size_t	first;
	size_t	last;
	size_t	pos;

	res = malloc(sizeof(char *) * (ft_np(str, c) + 1));
	if (!res)
		return (NULL);
	res[ft_np(str, c)] = 0;
	last = 0;
	first = 0;
	pos = 0;
	while (pos < ft_np(str, c))
	{
		ft_nextword(str, &first, &last, c);
		if (last == first)
			break ;
		res[pos] = ft_action(str, first, last);
		if (!res[pos])
			return (ft_free(res, pos));
		pos++;
	}
	return (res);
}
