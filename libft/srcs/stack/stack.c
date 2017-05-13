/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 20:52:28 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/13 22:08:21 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <types/stack.h>

t_stack	*stack_init(t_stack *st, size_t size)
{
	return ((t_stack *)array_init((t_array *)st, size));
}

t_stack	*stack_create(size_t size)
{
	return ((t_stack *)array_create(size));
}

BOOL	is_empty_stack(t_stack *st)
{
	return (!(BOOL)((t_array *)st)->used);
}

t_stack	*stack_push(t_stack *st, void *data)
{
	return (array_push((t_array *)st, (void *)data));
}

t_stack	*stack_pop(t_stack *st)
{
	return (array_pop((t_array *)st, NULL));
}
