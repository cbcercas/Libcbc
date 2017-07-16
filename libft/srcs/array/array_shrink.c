/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_shrink.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 07:33:40 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/13 21:17:55 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array/array.h>

/**
** @brief      Reduce the array capacity if needed
**
** @param      ar  The t_array
**
** @return     The t_array on success or NULL otherwise
*/

t_array	*array_shrink(t_array *ar)
{
	void	*n_array;
	size_t	needed_cap;

	needed_cap = (ar->used / ARRAY_MIN_SIZE + 1) * ARRAY_MIN_SIZE;
	if (needed_cap == ar->used)
		needed_cap += ARRAY_MIN_SIZE;
	if (needed_cap > ar->capacity)
	{
		if (!(n_array = ft_memalloc(ar->elem_size * needed_cap)))
			return (NULL);
		n_array = ft_memcpy(n_array, ar->array, ar->elem_size * ar->used);
		ft_memdel(&ar->array);
		ar->array = n_array;
		ar->capacity = needed_cap;
	}
	return (ar);
}
