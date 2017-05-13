/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 11:12:57 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/13 22:09:41 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string/ft_string.h>

/*
** @brief      insert str to the t_string at given position
**
** @param      string  The string
** @param[in]  str     The string to insert
** @param[in]  pos     The position
**
** @return     the t_string if success, NULL otherwise
*/

t_string	*string_insert(t_string *string, const char *str, size_t pos)
{
	size_t	len;

	if (!str)
		return (string);
	len = ft_strlen(str);
	if (!(string_growth_cap(string, string->len + len)))
		return (NULL);
	if (pos <= string->len)
		ft_memmove(string->s + pos + len, string->s + pos, string->len - pos);
	ft_memcpy(string->s + pos, str, len);
	string->len += len;
	return (string);
}

t_string	*string_insert_front(t_string *string, const char *str)
{
	return (string_insert(string, str, 0));
}

t_string	*string_insert_back(t_string *string, const char *str)
{
	return (string_insert(string, str, string->len));
}
