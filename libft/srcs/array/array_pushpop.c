/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_pushpop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 15:26:18 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/19 05:42:29 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array/array.h>

/*
** @brief      Add an element at the and of the array
**
** @param      array  The t_array
** @param[in]  data   The new element
**
** @return     The t_array pointer on success, NULL otherwise
*/

t_array	*array_push(t_array *array, const void *data)
{
	if (array->used == array->capacity)
		if (!(array = array_growth(array)))
			return (NULL);
	array_set_at(array, array->used, data);
	array->used += 1;
	return (array);
}

/*
** @brief      Remove the last element of the array
**
** @param      array  The t_array
** @param      poped A pointer to store the poped element
**
** @return     The t_array pointer on success, NULL otherwise
*/

t_array	*array_pop(t_array *array, void *poped)
{
	if (!array || array->used == 0)
		return (NULL);
	if (!(array_remove_at(array, array->used - 1, poped)))
		return (NULL);
	return (array);
}
