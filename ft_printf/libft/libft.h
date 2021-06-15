/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 23:53:38 by mchun             #+#    #+#             */
/*   Updated: 2021/02/09 01:05:04 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define BASE_UP	0
# define BASE_DOWN	1

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *dest, int c, size_t len);
void				ft_bzero(void *b, size_t len);

void				*ft_memcpy(void *dest, const void *src, size_t len);
void				*ft_memccpy(void *dest, const void *src, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *b, int c, size_t len);
int					ft_memcmp(const void *b1, const void *b2, size_t len);

size_t				ft_strlen(const char *c);
size_t				ft_strlcpy(char *restrict dst, const char *restrict src, \
									size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *big, const char *little, \
									size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t len);

int					ft_atoi(const char *nptr);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);

void				*ft_calloc(size_t number, size_t size);
char				*ft_strdup(const char *s);
char				*ft_substr(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s, const char *set);
char				*ft_itoa(int n);
char				**ft_split(char const *str, char c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

void				ft_lstadd_front(t_list **lst, t_list *new);

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*del)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), \
									void (*del)(void *));

int					ft_isspace(int c);

char				*ft_numtox(long long int num);
char				*ft_utoa(unsigned int n);
char				*ft_utox(unsigned int num);
char				*ft_ltoa(long n);
void				ft_putnbr_base_fd(long long n, int base, int fd, int mode);
void				ft_putunbr_base_fd(unsigned long long n, \
						int base, int fd, int mode);
int					ft_digitlen_base(long long num, int base);
int					ft_digitlen_ubase(unsigned long long num, int base);

#endif
