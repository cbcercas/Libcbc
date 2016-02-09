#ifndef LIBFTPRINTF
# define LIBFTPRINTF
# include <stdarg.h>
enum FLAG
{
	c,
	s,
};

typedef struct		s_arg
{
	unsigned		alternate:1; /* '#'' */
	unsigned		zero_pad:1; /* '0' */
	unsigned		left_pad:1; /* '-' */
	unsigned		blank_pos:1; /* ' ' */
	unsigned		sign_pos:1; /* '+' */
	unsigned		deci_conv:1; /* ''' */
	unsigned		min_width; 
	int				precision; /* .digit */
	char			conversion; /* char */
	
}					t_args;

int		ft_printf(const char * restrict format, ...);
char	*ft_get_flags(char **format, t_args	*sargs);
char	*ft_get_width(char **format, t_args *sargs, va_list *args);
char	*ft_get_precision(char **format, t_args *sargs, va_list *args);

#endif