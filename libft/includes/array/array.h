/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 21:51:03 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/24 15:09:24 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H
# include <stdlib.h>
# include <libft.h>
# include <types/bool.h>
# include <libftprintf.h>

# define ARRAY_MIN_SIZE 4U


typedef struct  s_array t_array;

struct  s_array
{
	void	*array;
	size_t	elem_size;
	size_t	used;
	size_t	capacity;
};

/**
** @file       array.c
**
** @brief      Creation and initialisation for t_array
*/
t_array	*array_create_cap(size_t size, size_t cap);
t_array *array_create(size_t size);

/**
** @file       array_growth.c
**
** @brief      enlarge the array capacity
*/
t_array	*array_growth_cap(t_array *array, size_t cap);
t_array	*array_growth(t_array *array);

/**
**@ file       array_shrink.c
**
** @brief      Reduce the array capacity if needed
*/
t_array	*array_shrink(t_array *array);

/**
** @file       array_setget.c
**
** @brief      Get and set the element at given position
**             /!\ get_at and set_at don't check if pos are valid
**             it is an internal fonction to the array lib /!\
*/
void	*array_get_at(t_array *array, size_t pos);
void	*array_set_at(t_array *array, size_t pos, const void *data);

/**
** @file       array_copy.c
**
** @brief      Copy an array into an other
*/
t_array *array_copy(t_array *dest_array, t_array *src_array);

/**
** @file       array_pushpop.c
**
** @brief      array_push: add an element at the end of the array
**             array_pop: extract an element at the end of the array
*/
t_array	*array_push(t_array *array, const void *data);
void	*array_pop(t_array *array, size_t pos);

/**
** @file       array_insert.c
**
** @brief      add an element to the array at the given pos
*/
t_array	*array_insert(t_array *array, size_t pos, const void *data);

/**
** @file       array_swap.c
**
** @brief      Swap two elements in the array
*/
BOOL	array_swap(t_array *array, size_t pos_a, size_t pos_b);

/**
** @file       array_destroy.c
**
** @brief      Destroy a t_array
*/
void	array_destroy(t_array *array);

#endif
