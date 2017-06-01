/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 15:25:13 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/13 20:08:18 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array/array.h>

/**
** @brief      Copy an array into an other
**             enlarge the destination array if needed
** @param      d_array  The destination array
** @param      s_array   The source array
**
** @return     The destination array or NULL otherwise
*/

t_array	*array_copy(t_array *d_array, t_array *s_array)
{
	if (s_array->used > d_array->capacity)
		if (!(array_growth(d_array)))
			return (NULL);
	d_array->used = s_array->used;
	return (ft_memmove(d_array->array, s_array->array, s_array->used \
				* s_array->elem_size));
}
