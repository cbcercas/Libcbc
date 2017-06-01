/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 01:20:04 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/13 20:08:24 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array/array.h"

/**
** @brief      Destroy a t_array
**
** @param      array  The t_array to be free
*/

void	array_destroy(t_array **array)
{
	ft_memdel(&(*array)->array);
	ft_memdel((void **)array);
}

/*
** @brief      Reset an array to default
**
** @param      array  The t_array
**
** @return     The t_array on success, NULL otherwise
*/

t_array	*array_reset(t_array *array)
{
	ft_memdel(&array->array);
	if (!(array_init_cap(array, array->elem_size, ARRAY_MIN_SIZE)))
	{
		free(array);
		return (NULL);
	}
	return (array);
}
