/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_pushpop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 15:26:18 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/23 21:06:15 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array/array.h>

/**
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

/**
** @brief      Extract an element of the array
**
** @param      array  The t_array
** @param[in]  pos    The element position
**
** @return     A pointer to the popped element
*/
void	*array_pop(t_array *array, size_t pos)
{
	void *poped;

	if (pos > array->used - 1)
		return (NULL);
	if (!(poped = ft_memalloc(array->elem_size)))
		return (NULL);
	ft_memcpy(poped, array_get_at(array, pos), array->elem_size);
	while (pos + 1 < array->used)
	{
		if (!array_swap(array, pos, pos + 1))
		{
			ft_memdel(&poped);
			return (NULL);
		}
		pos++;
	}
	array->used -= 1;
	ft_bzero(array_get_at(array, pos), array->elem_size);
	//shrink
	return (poped);
}
