#ifndef TYPE
# define TYPE

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
	c,
	C,
	d,
	i,
	o,
	O,
	p,
	s,
	S,
	u,
	x,
	X,
	per
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

#endif