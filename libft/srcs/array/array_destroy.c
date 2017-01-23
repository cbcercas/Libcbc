/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 01:20:04 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/23 21:05:58 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array/array.h"


/**
** @brief      Destroy a t_array
**
** @param      array  The t_array to be free
*/
void	array_destroy(t_array *array)
{
	free(array->array);
	free(array);
}