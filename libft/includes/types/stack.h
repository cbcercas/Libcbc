/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:44:49 by chbravo-          #+#    #+#             */
/*   Updated: 2017/03/04 08:10:10 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

#include <array/array.h>
#include <types/bool.h>
#include <stdlib.h>

typedef  t_array	t_stack;

#define stack_create(size) (t_stack *)array_create(size)
#define is_empty_stack(st) !(BOOL)st->used
#define stack_push(st, data) array_push((t_array *)st, (void*)data)
#define stack_pop(st) array_pop((t_array *)st, NULL)
#define get_top_stack(st) array_get_last((t_array *)st)
#define get_stack_length(st) st->used - 1
#define stack_destroy(st) array_destroy((t_array **)st)
#endif