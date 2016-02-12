#ifndef LIBFTPRINTF
# define LIBFTPRINTF
# include <stdarg.h>
enum flag
{
	 hh,
	 h,
	 l,
	 ll,
	 j,
	 z
};

enum conv
{
	s,
	S,
	p,
	d,
	D,
	i,
	o,
	O,
	u,
	U,
	x,
	X,
	c,
	C
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
	enum flag		len_modifier;
	enum conv		conversion;
}					t_args;

int		ft_printf(const char * restrict format, ...);
char	*ft_get_flags(char **format, t_args	*sargs);
char	*ft_get_width(char **format, t_args *sargs, va_list *args);
char	*ft_get_precision(char **format, t_args *sargs, va_list *args);
char	*ft_get_len_modifier(char **format, t_args *sargs);
char	*ft_get_conversion(char **format, t_args *sargs);

#endif