/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:14:57 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/19 05:44:11 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string/ft_string.h>

/*
** @brief      Replace the string in t_string by the str given
**
** @param      string  The t_string to replace
** @param[in]      str     The new string
**
** @return     The t_string on success, NULL otherwise
*/

t_string	*string_replace(t_string *string, const char *str)
{
	size_t	len;

	if (!string)
		return (NULL);
	len = ft_strlen(str);
	ft_strdel(&string->s);
	if (!(string_init_cap(string, STING_CAP_FROM_LEN(len))))
		return (NULL);
	ft_memcpy(string->s, str, len);
	string->len = len;
	return (string);
}

/*
** @brief      Replace the string in t_string by the n char of the str given
**
** @param      string  The t_string to replace
** @param[in]  str     The new string
** @param[in]  n       The size copied
**
** @return     The t_string on success, NULL otherwise
*/

t_string	*string_nreplace(t_string *string, const char *str, size_t size)
{
	size_t	len;

	if (!string)
		return (NULL);
	len = ft_strlen(str);
	if (len < size)
		size = len;
	ft_strdel(&string->s);
	if (!(string_init_cap(string, STING_CAP_FROM_LEN(size))))
		return (NULL);
	ft_memcpy(string->s, str, size);
	string->len = size;
	return (string);
}
