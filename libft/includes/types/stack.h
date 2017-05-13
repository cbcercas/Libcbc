/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:44:49 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/13 22:05:12 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <array/array.h>
# include <types/bool.h>
# include <stdlib.h>

typedef t_array	t_stack;

t_stack	*stack_init(t_stack *st, size_t size);
t_stack	*stack_create(size_t size);
BOOL	is_empty_stack(t_stack *st);
t_stack	*stack_push(t_stack *st, void *data);
t_stack	*stack_pop(t_stack *st);
t_stack	*get_top_stack(t_stack *st);
size_t	get_stack_length(t_stack *st);
void	stack_destroy(t_stack *st);
t_stack	*stack_reset(t_stack *st);

#endif
