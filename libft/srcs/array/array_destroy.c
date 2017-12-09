/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 01:20:04 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/19 05:42:16 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array/array.h"

/*
** @brief      Destroy a t_array
**
** @param      array  The t_array to be free
*/

void	array_destroy(t_array **array, void *fn(void *))
{
	size_t	cnt;

	cnt = 0;
	if (fn)
		while (cnt < (*array)->used)
			fn(array_get_at(*array, cnt++));
	ft_memdel(&(*array)->array);
	ft_memdel((void **)array);
}

/*
** @brief      Reset an array to default
**
** @param      array  The t_array
**
** @return     The t_array on success, NULL otherwise
** TODO add some test
*/

t_array	*array_reset(t_array *array, void *fn(void *))
{
	size_t	cnt;

	cnt = 0;
	if (fn && array->used)
		while (cnt < array->used)
			fn(array_get_at(array, cnt++));
	if (array->capacity > ARRAY_MIN_SIZE)
	{
		ft_memdel(&array->array);
		if (!(array_init_cap(array, array->elem_size, ARRAY_MIN_SIZE)))
			free(array);
	}
	else
	{
		ft_bzero(array->array, array->elem_size * array->capacity);
		array->used = 0;
	}
	return (array);
}
