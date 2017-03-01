/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:44:49 by chbravo-          #+#    #+#             */
/*   Updated: 2017/03/01 18:26:59 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

#include <array/array.h>
#include <types/bool.h>
#include <stdlib.h>

typedef struct s_array	*t_stack;

#define stack_create(size) array_create(size)
#define is_empty_stack(st) !(BOOL)st->used
#define stack_push(st, data) array_push(st, (void*)data)
#define stack_pop(st) array_pop(st, NULL)
#define get_top_stack(st) array_get_last(st)
#define get_stack_length(st) st->used - 1

#endif