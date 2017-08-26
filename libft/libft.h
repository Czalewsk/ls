/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:37:53 by czalewsk          #+#    #+#             */
/*   Updated: 2017/08/26 18:02:03 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIBFT_H
# define __LIBFT_H
# include <string.h>
# include <stdint.h>
# include "get_next_line.h"
# include "ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "array.h"

# define UC unsigned char
# define ABS(Value) (Value < 0 ? -Value : Value)

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

int				ft_intisbetween_inc(int value, int inf, int sup);
int				ft_atoi_bigendian(unsigned char *array, int nb_octet);
int				ft_strisnumber(char *str);
int				ft_atoi(const char *str);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_strcat(char *s1, const char *s2);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strdup(const char *s1);
int				ft_tolower(int c);
int				ft_toupper(int c);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strrstr(const char *big, const char *little);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
void			ft_putstr(char const *s);
void			ft_putchar(char c);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
char			*ft_itoa(intmax_t n);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lst_pushend(t_list **alst, t_list *new);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t			ft_lstlen(t_list *lst);
t_list			*ft_lst_newstr(char *str);
t_list			**ft_strsplit_lst(char const *s, char c);
void			*ft_memdup(const void *mem, size_t size);
int				ft_square(int nb);
void			ft_lst_remove_if(t_list **alst, int (*f)(t_list *elem),
		void (*del)(void *, size_t));
void			ft_lst_remove(t_list **alst, t_list *dl, void (*del)
		(void *, size_t));
char			*ft_strjoin_free(char *s1, int f1, char *s2, int f2);
void			*ft_memrealloc(void *addr, size_t old_size, size_t new_size);
void			*ft_memjoin_free(void *addr1, size_t size1, void *addr2,
		size_t size2);
int				ft_power(int nb, int power);
char			*ft_itoa_base(uintmax_t n, const char *base);
int				ft_atoi_base(char *str, const char *base);
size_t			ft_wstrlen(int *str);
size_t			ft_strlen_utf(const int *str);
size_t			ft_count_digit(char *str);
int				ft_isint(char *nb);
int				ft_howmany(char *line, char c);
void			ft_lst_remove_last(t_list **alst, void (*del)(void *, size_t));
void			ft_lst_remove_index(t_list **alst, int index,
		void (*del)(void *, size_t));
t_list			*ft_lst_cpy(t_list *lst, int r);
void			ft_lstinsert_if_end(t_list **alst, t_list *new,
		int (*f)(t_list *, t_list *));
void			ft_error(char *str, void (*f)(void));
char			ft_strcstr(char *str, char *chaine);
int				ft_isdouble(char *str);
long int		ft_atol(const char *str);
t_list			*ft_lst_return_index(t_list *lst, size_t index);
int				ft_isprint_wsp(int c);
char			*ft_cfextension(char *filename, char *extension);
int				get_param(int ac, char **av, char (*option)[128]);
void			ft_lst_add_index(t_list **alst, t_list *new, int index);

#endif
