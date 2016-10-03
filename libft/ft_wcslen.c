#include <wchar.h>
#include "libft.h"

size_t	ft_wcslen(const wchar_t *str)
{
	const wchar_t *c;

	c = str;
	while (*c)
		c++;
	return (c - str);
}
