#ifndef LIBFTPRINTF
#define LIBFTPRINTF

enum FLAG
{
	c;
	s;
};

int		ftprintf(const char * restrict format, ...);

#endif