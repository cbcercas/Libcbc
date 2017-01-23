/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_setget.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 15:22:15 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/23 23:06:22 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array/array.h>

void	array_set_at(t_array *array, size_t pos, const void *data)
{
	ft_memcpy(array_get_at(array, pos), data, array->elem_size);
}

/**
** @brief      Get the element at given position
**             /!\ Doesn't check if pos are valid
**             it is an internal fonction to the array lib /!\
**
** @param      array  The t_array
** @param[in]  pos    The element position
**
** @return     A pointer to the element
*/
void	*array_get_at(t_array *array, size_t pos)
{
	return (array->array + pos * array->elem_size);
}

/**
** @brief      Set the element with data given
**
** @param      array  The t_array
** @param[in]  pos    The element position
** @param[in]  data   The new data
*/
void	array_set(t_array *array, size_t pos, const void *data)
{
	if (pos >= array->used)
		return;
	ft_memcpy(array_get_at(array, pos), data, array->elem_size);
}

/**
** @brief      Get the element at given position
**
** @param      array  The t_array
** @param[in]  pos    The element position
**
** @return     A pointer to the element if exsist, NULL otherwise
*/
void	*array_get(t_array *array, size_t pos)
{
	if (pos >= array->used)
		return(NULL);
	return (array->array + pos * array->elem_size);
}
