/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_clean.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 23:15:23 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/19 05:43:42 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string/ft_string.h>

/*
** @brief      Reset a t_string to the default states
**
** @param      string  The string to reset
**
** @return     The t_string on success, NULL otherwise
*/

t_string	*string_reset(t_string *string)
{
	if (!string)
		return (NULL);
	ft_strdel(&string->s);
	return (string_init(string));
}

/*
** @brief      Delete a t_string
**
** @param      string  The string to delete
**
** @return     NULL
*/

t_string	*string_del(t_string **string)
{
	if (!string)
		return (NULL);
	if ((*string)->s)
		ft_strdel(&(*string)->s);
	ft_memdel((void**)string);
	return (NULL);
}
