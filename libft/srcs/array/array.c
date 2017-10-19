/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 21:51:25 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/19 05:41:05 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array/array.h>

/*
** @brief      Initialize the t_array with specified capacity
**
** @param      array  The array
** @param[in]  size   The elemeny size
** @param[in]  cap    The array capacity
**
** @return     The t_array pointer, NULL otherwise
*/

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

t_array	*array_init(t_array *array, size_t size)
{
	return (array_init_cap(array, size, ARRAY_MIN_SIZE));
}

/*
** @brief      Create a t_array with specified capacity
**
** @param[in]  size  The element size
** @param[in]  cap   The array capacity
**
** @return     A t_array pointer on success, NULL otherwise
*/

t_array	*array_create_cap(size_t size, size_t cap)
{
	t_array	*array;
	size_t	new_cap;

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

/*
** @brief      Create a t_array with default capacity
**
** @param[in]  size  The element size
**
** @return     A t_array pointer on success, NULL otherwise
*/

t_array	*array_create(size_t size)
{
	return (array_create_cap(size, ARRAY_MIN_SIZE));
}
