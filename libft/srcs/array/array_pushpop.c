/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_pushpop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 15:26:18 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/22 15:26:58 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array/array.h>

t_array	*array_push(t_array *array, const void *data)
{
	if (array->used == array->capacity)
		if (!(array = array_growth(array)))
			return (NULL);
	array_set_at(array, array->used, data);
	array->used += 1;
	return (array);
}