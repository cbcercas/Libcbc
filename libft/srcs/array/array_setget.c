/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_setget.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 15:22:15 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/23 23:05:26 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array/array.h>

void	array_set_at(t_array *array, size_t pos, const void *data)
{
	ft_memcpy(array_get_at(array, pos), data, array->elem_size);
}

void	*array_get_at(t_array *array, size_t pos)
{
	return (array->array + pos * array->elem_size);
}

void	array_set(t_array *array, size_t pos, const void *data)
{
	if (pos >= array->used)
		return;
	ft_memcpy(array_get_at(array, pos), data, array->elem_size);
}

void	*array_get(t_array *array, size_t pos)
{
	if (pos >= array->used)
		return(NULL);
	return (array->array + pos * array->elem_size);
}
