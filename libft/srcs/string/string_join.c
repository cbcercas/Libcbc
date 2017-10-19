/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 12:11:51 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/19 03:10:02 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string/ft_string.h>

/*
** @brief      Join two t_string into an other
**
** @param      s1    The first string
** @param      s2    The second string
**
** @return     return the new t_string
*/

t_string	*string_join(t_string *s1, t_string *s2)
{
	t_string	*string;

	if (!s1)
		return (string_clone(s2));
	if (!s2)
		return (string_clone(s1));
	if (!(string = string_create_cap(s1->len + s2->len)))
		return (NULL);
	string = string_insert(string, s1->s, 0);
	string->len = s1->len;
	string = string_insert_back(string, s2->s);
	return (string);
}

/*
** @brief      Join two t_string into an other.
**             And free source string if needed
**
** @param      s1    The first string
** @param      s2    The second string
** @param      free  The free switch
**
** @return     return the new t_string
*/

t_string	*string_join_cl(t_string **s1, t_string **s2, BOOL free)
{
	t_string	*string;

	if (!*s1)
		return (string_clone(*s2));
	else if (!*s2)
		return (string_clone(*s1));
	else
	{
		if (!(string = string_create_cap((*s1)->len + (*s2)->len)))
			return (NULL);
		string = string_insert(string, (*s1)->s, 0);
		string->len = (*s1)->len;
		string = string_insert_back(string, (*s2)->s);
	}
	if (free && *s1)
		string_del(s1);
	if (free && *s2)
		string_del(s2);
	return (string);
}
