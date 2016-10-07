#include <stdarg.h>
#include "type.h"
#include <printer.h>

int ft_print_p(t_args *sarg, va_list *larg)
{
	sarg->alternate = 1;
	sarg->len_modifier = l;
	return (ft_print_x(sarg, larg));
}