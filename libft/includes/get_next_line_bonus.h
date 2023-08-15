/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:53:43 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/11 14:38:57 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define BUFFER_SIZE (10)

char	*get_next_line_gnl(int fd);

char	*ft_strchr_gnl(const char *str, int c);

int		ft_strlen_gnl(const char *str);

char	*ft_strjoin_gnl(char *str1, char *str2);

char	*get_next_line(int fd);

#endif