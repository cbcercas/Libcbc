#include <stdarg.h>
#include "type.h"

#include <stdio.h>

int ft_print_d(t_args *sarg, va_list *larg)
{
	printf("In ft_print_d\n");
	if (!sarg && !larg)
		return (-1);
	return (0);
}