#ifndef NEW
# define NEW
# include <stdarg.h>
# include "type.h"
# include "printer.h"

int (*print[])(t_args *sarg, va_list *larg) = {
	ft_print_c,
	ft_print_C,
	ft_print_d,
	ft_print_D,
	ft_print_i,
	ft_print_o,
	ft_print_O,
	ft_print_p,
	ft_print_s,
	ft_print_S,
	ft_print_u,
	ft_print_U,
	ft_print_x,
	ft_print_X,
	ft_print_per,
	};

#endif