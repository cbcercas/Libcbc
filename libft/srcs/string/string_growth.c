/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_growth.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 11:08:45 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/19 03:09:54 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string/ft_string.h>

/*
** @brief      Growth the string with capacity
**
** @param      string  The t_string
** @param[in]  cap     The capacity
**
** @return     The t_string pointer on success, NULL otherwise
*/

t_string	*string_growth_cap(t_string *string, size_t cap)
{
	char	*new_string;
	size_t	new_cap;

	new_cap = (cap / ARRAY_MIN_SIZE + 1) * ARRAY_MIN_SIZE;
	if (new_cap < string->capacity)
		return (string);
	if (!(new_string = ft_memalloc(new_cap)))
		return (NULL);
	new_string = ft_memcpy(new_string, string->s, string->len);
	ft_strdel(&string->s);
	string->s = new_string;
	string->capacity = new_cap;
	return (string);
}

/*
** @brief      Groth the string without capacity
**
** @param      string  The t_string
**
** @return     The t_string pointer on success, NULL otherwise
*/

t_string	*string_growth(t_string *string)
{
	return (string_growth_cap(string, string->capacity + 1));
}
