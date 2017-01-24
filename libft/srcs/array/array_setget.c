/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_setget.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 15:22:15 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/24 13:40:36 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array/array.h>

/**
** @brief      Set the element with data given
**
** @param      array  The t_array
** @param[in]  pos    The element position
** @param[in]  data   The new data
**
** @return     Apointer to the element set if success, NULL otherwise
*/
void	*array_set_at(t_array *array, size_t pos, const void *data)
{
	if (pos > array->capacity)
		return (NULL);
	return (ft_memcpy(array_get_at(array, pos), data, array->elem_size));
}

/**
** @brief      Get the element at given position
**
** @param      array  The t_array
** @param[in]  pos    The element position
**
** @return     A pointer to the element
*/
void	*array_get_at(t_array *array, size_t pos)
{
	if (pos > array->capacity)
		return (NULL);
	return (array->array + pos * array->elem_size);
}
