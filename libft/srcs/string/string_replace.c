/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:14:57 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/13 20:31:44 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string/ft_string.h>

/**
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
