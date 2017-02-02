/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 01:09:53 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/02 04:44:03 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string/ft_string.h>

/**
** @name       string_dup
**
** @brief      copies at most n characters from the string str
**             always NUL terminating the copied string.
**             if str is NULL return a t_string with default capacity
**
** @param[in]  str   The string
** @param[in]  n     The length
**
** @return     A pointer to the new created t_string
*/
t_string	*string_dup(const char *str)
{
	if (!str)
		return (string_create());
	return (string_ndup(str, ft_strlen(str)));
}

/**
** @name       string_ndup
**
** @brief      copies at most n characters from the string str
**             always NULL terminating the copied string.
**             if str is NULL return a t_string with capacity n
**
** @param[in]  str   The string
** @param[in]  n     The length
**
** @return     A pointer to the new created t_string
*/
t_string	*string_ndup(const char *str, size_t n)
{
	t_string *string;
	size_t strlen;

	if (!str)
		return (string_create_cap(n));
	strlen = ft_strlen(str);
	if (!(string = string_create_cap(n)))
		return (NULL);
	ft_memcpy(string->s, str, (n > strlen) ? strlen : n);
	string->len = (n > strlen) ? strlen : n;
	return (string);
}
