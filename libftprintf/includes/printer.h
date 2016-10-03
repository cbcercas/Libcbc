#ifndef PRINT_FUNC
# define PRINT_FUNC
# include <stdarg.h>
# include "type.h"

int ft_print_c(t_args *sarg, va_list *larg);
int ft_print_C(t_args *sarg, va_list *larg);
int ft_print_d(t_args *sarg, va_list *larg);
int ft_print_i(t_args *sarg, va_list *larg);
int ft_print_o(t_args *sarg, va_list *larg);
int ft_print_O(t_args *sarg, va_list *larg);
int ft_print_p(t_args *sarg, va_list *larg);
int ft_print_s(t_args *sarg, va_list *larg);
int ft_print_S(t_args *sarg, va_list *larg);
int ft_print_u(t_args *sarg, va_list *larg);
int ft_print_x(t_args *sarg, va_list *larg);
int ft_print_X(t_args *sarg, va_list *larg);
int ft_print_per(t_args *sarg, va_list *larg);

#endif