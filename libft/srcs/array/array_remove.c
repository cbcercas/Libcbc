/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:40:17 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/19 05:42:44 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array/array.h>

/*
**TODO: DOC
*/

t_array	*array_remove_at(t_array *array, size_t pos, void *removed)
{
	void	*p;
	size_t	len;

	if (pos > array->used - 1)
		return (NULL);
	p = array_get_at(array, pos);
	if (removed != NULL)
		ft_memcpy(removed, p, array->elem_size);
	array->used -= 1;
	len = (array->used - pos) * array->elem_size;
	ft_memmove(p, p + array->elem_size, len);
	if (!(array_shrink(array)))
		return (NULL);
	return (array);
}
