/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:45:56 by chbravo-          #+#    #+#             */
/*   Updated: 2017/03/01 18:32:08 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <headers.h>

static void teardown(void) {
	return;
}

TestSuite(stack, .disabled = DISABLE_STACK_TEST, .fini = teardown);

Test(stack, Test_stack) {
	t_stack stack;
	int a = 1;
	int *b;

	stack = stack_create(sizeof(int));
	cr_expect(stack != NULL, "Stack creation failed");
	stack_push(stack, &a);
	a++;
	stack_push(stack, &a);
	a++;
	stack_push(stack, &a);
	b = (int*)get_top_stack(stack);
	cr_expect(*b == 3, "Bad Top of stack: need 3, is %d!", *b);
	stack_pop(stack);
	b = (int*)get_top_stack(stack);
	cr_expect(*b == 2, "Bad Top of stack: need 2, is %d!", *b);
	cr_expect(is_empty_stack(stack) == false, "Stack is empty!");
	cr_expect(get_stack_length(stack) == 1, "Bad stack lenght, need 1, is %zu", get_stack_length(stack));
}
