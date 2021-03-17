/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:23:26 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/10 15:54:55 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

# define BASE_10 "0123456789"
# define BASE_16 "0123456789abcdef"
# define BASE_8 "01234567"

typedef struct	s_lst
{
	void			*cont;
	struct s_lst	*next;
}				t_lst;

typedef struct	s_dclst
{
	char			c;
	struct s_dclst	*next;
	struct s_dclst	*prev;
}				t_dclst;

typedef struct	s_dlst
{
	void			*cont;
	struct s_dlst	*next;
	struct s_dlst	*prev;
}				t_dlst;

void			*ft_memset(void *str, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, char const *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *st1, const char *st2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_intlen(int nbr);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *str, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_putchar_fd(char c, int fd);
int				ft_putstr_fd(const char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_lst			*ft_lstnew(void *content);
void			ft_lstadd_front(t_lst **lst, t_lst *new_);
void			ft_lstadd_sorted(t_lst **head, t_lst *new_,
								int (*cmp)(void *, void *));
int				ft_lstsize(t_lst *lst);
t_lst			*ft_lstlast(t_lst *lst);
int				ft_lstlen(t_lst *lst);
void			ft_lstadd_back(t_lst **lst, t_lst *new_);
void			ft_lstdelone(t_lst *lst, void (*del)(void *));
void			ft_lstclear(t_lst **lst, void (*del)(void *));
t_lst			*ft_lstfind(t_lst *lst, void *data, int (*f)(void *, void *));
void			ft_lstiter(t_lst *lst, void (*f)(void *));
void			ft_lstrm_if(t_lst **head, void *data,
				int (*cmp)(void *, void *), void (*del)(void *));
t_lst			*ft_lstrm(t_lst **lst,
				char (*f)(void *, int, int), int x, int y);
t_lst			*ft_lstmap(t_lst *lst, void *(*f)(void *), void (*del)(void *));
int				nbr_len(size_t nbr, int base);
char			*ft_stoa_base(size_t nbr, char base);
char			ft_is_in_charset(char c, const char *charset);
void			ft_putnbr_base(size_t nbr, const char *base);
t_dclst			*ft_dclst_new(char c);
void			ft_dclst_insert(t_dclst **lst, t_dclst *new_);
void			ft_dclst_delete(t_dclst **lst);
void			ft_dclst_clear(void *lst);
void			*ft_dupdclst(void *lst);
t_dlst			*ft_dlst_new(void *cont);
void			ft_dlst_insert(t_dlst **lst, t_dlst *new_);
t_dlst			*ft_dlst_addfront(t_dlst **lst, t_dlst *new_);
void			ft_dlst_delete(t_dlst **lst);
t_dlst			*ft_dupdlst(t_dlst *lst, void *(*dup)(void *),
							void (*clear)(void *));
void			ft_dlst_clear(t_dlst **lst, void (*clear)(void *));
void			*ft_dupdclst_partial(void *lst_);
t_dclst			*get_head(t_dclst *it);
#endif
