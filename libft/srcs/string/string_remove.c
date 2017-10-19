/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 01:08:49 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/19 03:10:09 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string/ft_string.h>

/*
** @brief      remove n char of a t_string from pos
**
** @param      s     The t_string
** @param[in]  pos   The position to start remove
** @param[in]  n   The number of char to remove
**
** @return     The number of removed char
*/

size_t	string_remove(t_string *s, size_t pos, size_t n)
{
	size_t	rem;

	if (!s || pos >= s->len)
		return (0);
	if (s->len > pos + n)
	{
		ft_memmove(s->s + pos, s->s + pos + n, s->len - (pos + n));
		rem = n;
	}
	else
		rem = s->len - pos;
	s->len = s->len - rem;
	ft_bzero(s->s + s->len, s->capacity - s->len);
	return (rem);
}

/*
** @brief      remove a char of a t_string at pos
**
** @param      s     The t_string
** @param[in]  pos   The position of the removed char
**
** @return     The number of removed char
*/

size_t	string_remove_char(t_string *s, size_t pos)
{
	return (string_remove(s, pos, 1));
}
