/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 21:51:25 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/22 15:26:50 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array/array.h>

t_array	*array_init_cap(t_array *array, size_t size, size_t cap)
{
	if (size == 0)
		return (NULL);
	array->capacity = cap;
	if (array->capacity < ARRAY_MIN_SIZE)
		array->capacity = ARRAY_MIN_SIZE;
	array->elem_size = size;
	if (!(array->array = ft_memalloc(array->elem_size * array->capacity)))
		return (NULL);
	array->used = 0;
	return (array);
}

t_array	*array_create_cap(size_t size, size_t cap)
{
	t_array *array;
	size_t new_cap;

	new_cap = (cap / ARRAY_MIN_SIZE + 1) * ARRAY_MIN_SIZE;
	if (!(array = ft_memalloc(sizeof(*array))))
		return (NULL);
	if (!(array_init_cap(array, size, new_cap)))
	{
		free(array);
		return (NULL);
	}
	return (array);
}

t_array *array_create(size_t size)
{
	return(array_create_cap(size, ARRAY_MIN_SIZE));
}
