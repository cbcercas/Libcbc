/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_growth.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 15:17:51 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/23 21:54:32 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array/array.h>

/**
** @brief      Growth the array with capacity
**
** @param      array  The t_array
** @param[in]  cap    The capacity
**
** @return     The t_array pointer on success, NULL otherwise
*/
t_array	*array_growth_cap(t_array *array, size_t cap)
{
	void	*new_array;
	size_t	new_cap;

	new_cap = (cap / ARRAY_MIN_SIZE + 1) * ARRAY_MIN_SIZE;
	if (new_cap < array->capacity)
		return (NULL);
	if (!(new_array = ft_memalloc(array->elem_size * new_cap)))
		return (NULL);
	new_array = ft_memcpy(new_array, array->array, array->elem_size * array->used);
	ft_memdel(&array->array);
	array->array = new_array;
	array->capacity = new_cap;
	return(array);
}

/*
** @brief      Groth the array without capacity
**
** @param      array  The t_array
**
** @return     The t_array pointer on success, NULL otherwise
*/
t_array	*array_growth(t_array *array)
{
	return(array_growth_cap(array, array->capacity + 1));
}
