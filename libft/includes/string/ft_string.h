/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 18:18:20 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/15 02:33:00 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H
# include <libft.h>
# include <types/bool.h>

# define STRING_MIN_SIZE 8U
# define STING_CAP_FROM_LEN(len) (len / STRING_MIN_SIZE + 1) * STRING_MIN_SIZE

typedef struct s_string	t_string;

/**
** @struct    s_string
**
** @brief     The struct used in string lib
**
** @var s_string::s
**            A pointer to the string
** @var s_string::len
**            The string length
** @var s_string::capacity
**            The current capacity of the string
*/
struct		s_string
{
	char	*s;
	size_t	len;
	size_t	capacity;
};

/**
** @file       string.c
**
** @brief      Creation and initialisation for t_string
*/

t_string	*string_init_cap(t_string *string, size_t cap);
t_string	*string_create_cap(size_t cap);
t_string	*string_create(void);
t_string	*string_init(t_string *string);

/**
** @file       string_growth.c
**
** @brief      enlarge the string capacity
*/
t_string	*string_growth_cap(t_string *array, size_t cap);
t_string	*string_growth(t_string *array);

/**
** @file       string_shrink.c
**
** @brief      reduce the string capacity to feet the string len
*/
t_string	*string_shrink(t_string *string);

/**
** @file       string_dup.c
**
** @brief      create a t_string from a char*
*/
t_string	*string_ndup(const char *str, size_t n);
t_string	*string_dup(const char *str);

/**
** @file       string_clone.c
**
** @brief      clone a t_string
*/
t_string	*string_clone(const t_string *string);

/**
** @file       string_insert.c
**
** @brief      insert a char* to the t_string
*/
t_string	*string_insert(t_string *string, const char *str, size_t pos);
t_string	*string_ninsert(t_string *s, const char *str, size_t pos, size_t n);
t_string	*string_insert_front(t_string *string, const char *str);
t_string	*string_insert_back(t_string *string, const char *str);

/**
** @file       string_join.c
**
** @brief      Join two t_string into an other
*/
t_string	*string_join(t_string *s1, t_string *s2);
t_string	*string_join_cl(t_string **s1, t_string **s2, BOOL free);

/**
** @file       string_clean.c
**
** @brief      Fonction to clear and destroy a t_string
*/
t_string	*string_reset(t_string *string);
t_string	*string_del(t_string **string);

/**
** @file       string_remove.c
**
** @brief      Remove part of t_string
*/
size_t		string_remove(t_string *s, size_t pos, size_t len);
size_t		string_remove_char(t_string *s, size_t pos);

/**
** @file       string_replace.c
**
** @brief      Replace string in t_string
*/
t_string	*string_replace(t_string *string, const char *str);
t_string	*string_nreplace(t_string *string, const char *str);

#endif
