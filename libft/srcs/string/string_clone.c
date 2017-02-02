/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_clone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 03:53:54 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/02 04:49:34 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string/ft_string.h>

/**
** @brief      Copy a t_string into a new t_string
**
** @param[in]  string  The string to clone
**
** @return     The new malloced t_string
*/
t_string	*string_clone(const t_string *string)
{
	t_string	*nstring;

	if (!string)
		return (NULL);
	if (!(nstring = string_create_cap(string->capacity - 1)))
		return (NULL);
	nstring->s = ft_memcpy(nstring->s, string->s, string->len);
	nstring->len = string->len;
	return (nstring);
}