/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_shrink.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 02:51:58 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/19 05:44:17 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string/ft_string.h>

/*
** @brief      Reduce the string capacity if needed
**
** @param      string  The t_t_string
**
** @return     The t_string on success or NULL otherwise
*/

t_string	*string_shrink(t_string *string)
{
	char	*new_str;
	size_t	needed_cap;

	needed_cap = (string->len / STRING_MIN_SIZE + 1) * STRING_MIN_SIZE;
	if (needed_cap == string->len)
		needed_cap += STRING_MIN_SIZE;
	if (needed_cap < string->capacity)
	{
		if (!(new_str = ft_strnew(needed_cap)))
			return (NULL);
		new_str = ft_memcpy(new_str, string->s, string->len);
		ft_strdel(&string->s);
		string->s = new_str;
		string->capacity = needed_cap;
	}
	return (string);
}
