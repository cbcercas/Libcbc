/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 21:51:03 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/22 15:24:50 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H
# include <stdlib.h>
# include <libft.h>
#include <libftprintf.h>

# define ARRAY_MIN_SIZE 4U


typedef struct  s_array t_array;

struct  s_array
{
	void	*array;
	size_t	elem_size;
	size_t	used;
	size_t	capacity;
};

/*
**	array.c
*/
t_array	*array_init_cap(t_array *array, size_t size, size_t cap);
t_array	*array_create_cap(size_t size, size_t cap);
t_array	*array_push(t_array *array, const void *data);
void	array_set_at(t_array *array, size_t pos, const void *data);
t_array *array_create(size_t size);

/*
** array_growth.c
*/
t_array	*array_growth_cap(t_array *array, size_t cap);
t_array	*array_growth(t_array *array);

/*
** array_setget.c
*/
void	array_set_at(t_array *array, size_t pos, const void *data);

/*
** array_copy.c
*/
t_array *array_copy(t_array *dest_array, t_array *src_array);

/*
** array_pushpop.c
*/
t_array	*array_push(t_array *array, const void *data);

/*
**	array_destroy.c
*/
void	array_destroy(t_array *array);



#endif
