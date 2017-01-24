/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 18:07:19 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/24 15:02:23 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array/array.h>

/**
** @brief      Swap two elements in the array
**
** @param      array  The t_array
** @param[in]  pos_a  The first element position
** @param[in]  pos_b  The second element position
**
** @return     A bool: true on success, false otherwise
*/
BOOL	array_swap(t_array *array, size_t pos_a, size_t pos_b)
{
	void	*tmp;
	if ((pos_a >= array->capacity) || (pos_b >= array->capacity))
		return (false);
	if(!(tmp = ft_memalloc(array->elem_size)))
		return (false);
	ft_memcpy(tmp, array_get_at(array, pos_a), array->elem_size);
	ft_memcpy(array_get_at(array, pos_a), array_get_at(array, pos_b), array->elem_size);
	ft_memcpy(array_get_at(array, pos_b), tmp, array->elem_size);
	ft_memdel(&tmp);
	return (true);
}