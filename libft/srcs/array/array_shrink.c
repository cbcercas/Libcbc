/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_shrink.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 07:33:40 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/24 08:32:30 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array/array.h>

/**
** @brief      Reduce the array capacity if needed
**
** @param      array  The t_array
**
** @return     The t_array on success or NULL otherwise
*/
t_array	*array_shrink(t_array *array)
{
	void	*new_array;
	size_t	needed_cap;

	needed_cap = (array->used / ARRAY_MIN_SIZE + 1) * ARRAY_MIN_SIZE;
	if (needed_cap < array->capacity)
	{
		if (!(new_array = ft_memalloc(array->elem_size * needed_cap)))
			return (NULL);
		new_array = ft_memcpy(new_array, array->array, array->elem_size * array->used);
		ft_memdel(&array->array);
		array->array = new_array;
		array->capacity = needed_cap;
	}
	return (array);
}