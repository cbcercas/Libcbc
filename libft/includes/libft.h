/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:02:51 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/15 01:59:31 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>

# include <types/bool.h>
# include <array/array.h>
# include <inttypes.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

size_t			ft_strlen(const char *str);
int				ft_isalpha(int n);
int				ft_isdigit(int n);
int				ft_isalnum(int n);
int				ft_isascii(int nb);
int				ft_isprint(int nb);
BOOL			ft_isprintstr(char const *str);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strstr(const char *str, const char *to_find);
char			*ft_strnstr(const char *str, const char *to_find, size_t n);
void			*ft_memset(void *b, int c, size_t n);
void			ft_bzero(void *s, size_t n);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strdup(const char *src);
char			*ft_strdup_free(char *src, int free);
char			*ft_strndup_free(char *src, size_t start, size_t size, \
																int free);
void			*ft_memcpy(void *s1, const void *s2, size_t n);
void			*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void			*ft_memmove(void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dst, const char *src, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_iswhitespace(const char c);
int				ft_atoi(const char *str);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_striter(char *s, void (*f)(char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int nb);
char			*ft_itoa_base(long long int n, int base);
char			*ft_uitoa_base(unsigned long long nb, int base);
void			ft_putchar(char c);
int				ft_putc_in(int c);
int				ft_putc_out(int c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *lst);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int				ft_countchiffres(int nb);
size_t			ft_wordlen(char const *s, char c);
size_t			ft_nbword(char const *s, char c);
void			ft_freetab(char **array, size_t nb);
int				ft_countdigit(intmax_t num);
size_t			ft_tablen(char **array);
char			**ft_strtabdup(char **array);
/*
** Make full test before use
*/
char			*ft_strjoincl(char *s1, char *s2, int free);
void			ft_putnstr(char const *s, size_t len);
void			ft_putnstr_fd(char const *s, size_t len, int fd);
size_t			ft_wcslen(const wchar_t *str);
void			ft_putwstr_fd(wchar_t *str, int fd);
void			ft_putwstr(wchar_t *str);
char			*ft_uitobase(uintmax_t nb, unsigned int base);
char			*ft_imtoa(intmax_t num);
char			*ft_uimtoa(uintmax_t num);
char			*ft_uitooctal(uintmax_t nb, int prefix);
char			*ft_uitohex(uintmax_t nb, int uppercase);
void			ft_putwchar(wchar_t c);
void			ft_putwchar_fd(wchar_t c, int fd);
char			*ft_strrev(char *str);
char			*ft_strclean(char *str);

char			*ft_ctostr(char c, int nb);
char			*ft_wctostr(wchar_t c);
char			*ft_wstostr(wchar_t *ws);

void			ft_lstpush_back(t_list **head, t_list *lst);
void			ft_lstpush_front(t_list **head, t_list *lst);
t_list			*ft_lstpush(t_list **head, t_list *lst, int place);
#endif
