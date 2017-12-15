/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 18:22:41 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/19 05:43:38 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string/ft_string.h>

/*
** @brief      Initialize the t_string with specified capacity
**
** @param[out] string The t_string
** @param[in]  cap    The string capacity
**
** @return     The t_string pointer, NULL otherwise
*/

t_string	*string_init_cap(t_string *string, size_t cap)
{
	string->capacity = cap;
	if (string->capacity < STRING_MIN_SIZE)
		string->capacity = STRING_MIN_SIZE;
	if (!(string->s = ft_strnew(string->capacity)))
		return (string_del(&string));
	string->len = 0;
	return (string);
}

/*
** @brief      Create a t_string with specified capacity
**
** @param[in]  cap   The array capacity
**
** @return     A t_string pointer on success, NULL otherwise
*/

t_string	*string_create_cap(size_t cap)
{
	t_string	*string;
	size_t		new_cap;

	new_cap = (cap / STRING_MIN_SIZE + 1) * STRING_MIN_SIZE;
	if (!(string = ft_memalloc(sizeof(*string))))
		return (NULL);
	if (!(string = string_init_cap(string, new_cap)))
	{
		ft_memdel((void**)&string);
		return (NULL);
	}
	return (string);
}

t_string	*string_create(void)
{
	return (string_create_cap(1));
}

t_string	*string_init(t_string *string)
{
	return (string_init_cap(string, 0));
}
