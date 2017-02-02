/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 11:12:57 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/02 11:53:47 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string/ft_string.h>

/**
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
	if (pos < len)
		ft_memmove(string->s + pos + len, string->s + pos, len);
	ft_memcpy(string->s + pos, str, len);
	return (string);
}