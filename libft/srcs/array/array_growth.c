/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_growth.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 15:17:51 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/22 15:18:37 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array/array.h>

t_array	*array_growth_cap(t_array *array, size_t cap)
{
	t_array	*new_array;

	if (!(new_array = array_create_cap(array->elem_size, cap)))
		return (NULL);
	new_array = array_copy(new_array, array);
	array_destroy(array);
	return(new_array);
}

t_array	*array_growth(t_array *array)
{
	return(array_growth_cap(array, array->capacity + 1));
}