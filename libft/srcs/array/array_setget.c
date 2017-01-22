/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_setget.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 15:22:15 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/22 15:24:36 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array/array.h>

void	array_set_at(t_array *array, size_t pos, const void *data)
{
	ft_memcpy(array->array + pos * array->elem_size, data, array->elem_size);
}