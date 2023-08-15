/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:33:44 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/11 16:55:11 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "ft_printf.h"
# include "get_next_line_bonus.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

long				ft_atoi(const char *str);

void				ft_bzero(void *a, size_t n);

void				*ft_calloc(size_t n, size_t t);

void				*ft_free_charpp(char **to_free);

int					ft_isalnum(int c);

int					ft_isalpha(int c);

int					ft_isascii(int c);

int					ft_isdigit(int c);

int					ft_isprint(int c);

char				*ft_itoa(int n);

void				ft_lstadd_back(t_list **lst, t_list *newbe);

void				ft_lstadd_front(t_list **lst, t_list *newbe);

void				ft_lstclear(t_list **lst, void (*del)(void *));

void				ft_lstdelone(t_list *lst, void (*del)(void *));

void				ft_lstiter(t_list *lst, void (*f)(void *));

t_list				*ft_lstlast(t_list *lst);

t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

t_list				*ft_lstnew(void *content);

int					ft_lstsize(t_list *lst);

void				*ft_memchr(const void *str, int c, size_t n);

int					ft_memcmp(const void *str, const void *str2, size_t n);

void				*ft_memcpy(void *dest, const void *src, size_t n);

void				*ft_memmove(void *dest, const void *src, size_t n);

void				*ft_memset(void *a, int c, size_t n);

void				ft_putchar_fd(char c, int fd);

void				ft_putendl_fd(char *s, int fd);

void				ft_putnbr_fd(int n, int fd);

void				ft_putstr_fd(char *s, int fd);

char				**ft_split(char const *str, char c);

char				*ft_strchr(const char *str, int c);

char				*ft_strdup(const char *str);

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

char				*ft_strjoin(const char *str1, const char *str2);

size_t				ft_strlcat(char *dest, const char *src, size_t size);

size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t				ft_strlen(const char *str);

void				ft_strcpy(char *dest, const char *src);

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int					ft_strncmp(char const *s1, char const *s2, size_t n);

char				*ft_strnstr(const char *str, const char *to_find, size_t n);

char				*ft_strrchr(const char *str, int c);

char				*ft_strtrim(const char *str, const char *set);

char				*ft_substr(const char *str, unsigned int start, size_t len);

int					ft_tolower(int c);

int					ft_toupper(int c);

#endif