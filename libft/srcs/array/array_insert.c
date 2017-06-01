/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 12:42:54 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/13 20:08:32 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array/array.h>

/**
** @brief      add an element to the array at the given pos
**
** @param      array  The t_array
** @param[in]  pos    The element position
** @param[in]  data   The new data
**
** @return     A pointer to the element inserted if success, NULL otherwise
*/

t_array	*array_insert(t_array *array, size_t pos, const void *data)
{
	size_t count;

	if (!data)
		return (NULL);
	if (array->used >= array->capacity)
		if (!(array = array_growth(array)))
			return (NULL);
	count = array->used;
	while (count >= pos)
	{
		array_swap(array, count, count + 1);
		count -= 1;
	}
	return (array_set_at(array, pos, data));
}
