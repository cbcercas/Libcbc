#ifndef FT_GET
# define FT_GET
# include <stdarg.h>
# include "type.h"

char	*ft_get_flags(char **format, t_args	*sargs);
char	*ft_get_width(char **format, t_args *sargs, va_list *args);
char	*ft_get_precision(char **format, t_args *sargs, va_list *args);
char	*ft_get_len_modifier(char **format, t_args *sargs);
char	*ft_get_conversion(char **format, t_args *sargs);

#endif