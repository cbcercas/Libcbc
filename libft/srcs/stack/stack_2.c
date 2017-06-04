/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 22:06:18 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/13 22:09:14 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <types/stack.h>

t_stack		*get_top_stack(t_stack *st)
{
	return (array_get_last((t_array *)st));
}

size_t		get_stack_length(t_stack *st)
{
	return ((st->used) ? st->used - 1 : 0);
}

void		stack_destroy(t_stack **st, void fn(void *))
{
	return (array_destroy((t_array **)st, fn));
}

t_stack		*stack_reset(t_stack *st, void fn(void *))
{
	return (array_reset((t_array *)st, fn));
}
