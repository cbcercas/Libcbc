#ifndef UTILS
# define UTILS
# include <stdarg.h>
# include "type.h"

int			ft_print_pad(int len_res, int pad, char c);
intmax_t	ft_signed_from_lenght(t_args *sarg, intmax_t nb);
uintmax_t	ft_unsigned_from_lenght(t_args *sarg, uintmax_t nb);

#endif