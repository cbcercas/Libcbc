/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 15:25:13 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/24 14:54:00 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array/array.h>

/**
** @brief      Copy an array into an other
**             enlarge the destination array if needed
** @param      dest_array  The destination array
** @param      src_array   The source array
**
** @return     The destination array or NULL otherwise
*/
t_array *array_copy(t_array *dest_array, t_array *src_array)
{
	if (src_array->used > dest_array->capacity)
		if (!(array_growth(dest_array)))
			return (NULL);
	dest_array->used = src_array->used;
	return(ft_memmove(dest_array->array, src_array->array, src_array->used * src_array->elem_size));
}
