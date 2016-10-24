#ifndef TYPE
# define TYPE

enum				flag
{
	zero,
	hh,
	h,
	l,
	ll,
	j,
	z
};

enum				conv
{
	zeroo,
	c,
	C,
	d,
	i,
	o,
	p,
	s,
	S,
	u,
	x,
	X,
	per,
	def
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
	unsigned		precision:1;
	unsigned		precision_len; /* .digit */
	enum flag		len_modifier;
	enum conv		conversion;
	char			defchar;
}					t_args;

#endif