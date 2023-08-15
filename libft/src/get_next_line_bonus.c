/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:10:57 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/11 14:35:54 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*free_all(char *buffer, char *aux)
{
	free(buffer);
	free(aux);
	return (NULL);
}

static char	*buff_empty(char *buffer)
{
	int		i;
	int		j;
	char	*new_buff;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	new_buff = malloc(sizeof(char) * (ft_strlen_gnl(buffer) - i + 1));
	if (!new_buff)
	{
		free(new_buff);
		return (NULL);
	}
	i++;
	while (buffer[i])
		new_buff[j++] = buffer[i++];
	new_buff[j] = '\0';
	free(buffer);
	return (new_buff);
}

static char	*str_fuller(char *buffer)
{
	char	*str;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*buff_fuller(char *buffer, int fd)
{
	char	*aux;
	int		read_count;

	aux = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!aux)
		return (NULL);
	read_count = 1;
	while (read_count != 0 && !ft_strchr_gnl(buffer, '\n'))
	{
		read_count = read(fd, aux, BUFFER_SIZE);
		if (read_count == -1 || (read_count == 0 && !buffer))
			return (free_all(buffer, aux));
		aux[read_count] = '\0';
		if (!buffer)
		{
			buffer = malloc(sizeof(char) * 1);
			buffer[0] = '\0';
		}
		buffer = ft_strjoin_gnl(buffer, aux);
	}
	free(aux);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[256];
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = buff_fuller(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	str = str_fuller(buffer[fd]);
	buffer[fd] = buff_empty(buffer[fd]);
	return (str);
}
