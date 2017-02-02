/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbc_string.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 18:18:20 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/02 03:27:32 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H
# include <libft.h>

# define STRING_MIN_SIZE 8U

typedef struct	s_string t_string;

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
struct s_string
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

/**
** @file       string_growth.c
**
** @brief      enlarge the string capacity
*/
t_string	*string_growth_cap(t_string *array, size_t cap);
t_string	*string_growth(t_string *array);

/**
** @file       string_dup.c
**
** @brief      create a t_string from a char*
*/
t_string	*string_ndup(const char *str, size_t n);
t_string	*string_dup(const char *str);

#endif