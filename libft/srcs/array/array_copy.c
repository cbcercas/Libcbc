/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 15:25:13 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/22 15:25:56 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array/array.h>

t_array *array_copy(t_array *dest_array, t_array *src_array)
{
	dest_array->used = src_array->used;
	return(ft_memmove(dest_array, src_array, src_array->used * src_array->elem_size));
}
