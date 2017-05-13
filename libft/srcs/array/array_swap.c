/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 18:07:19 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/13 20:23:11 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array/array.h>

/*
** @brief      Swap two elements in the array
**
** @param      array  The t_array
** @param[in]  pos_a  The first element position
** @param[in]  pos_b  The second element position
**
** @return     A bool: true on success, false otherwise
*/

BOOL	array_swap(t_array *ar, size_t pos_a, size_t pos_b)
{
	void	*tmp;

	if ((pos_a >= ar->capacity) || (pos_b >= ar->capacity))
		return (false);
	if (!(tmp = ft_memalloc(ar->elem_size)))
		return (false);
	ft_memcpy(tmp, array_get_at(ar, pos_a), ar->elem_size);
	ft_memcpy(array_get_at(ar, pos_a), array_get_at(ar, pos_b), ar->elem_size);
	ft_memcpy(array_get_at(ar, pos_b), tmp, ar->elem_size);
	ft_memdel(&tmp);
	return (true);
}
