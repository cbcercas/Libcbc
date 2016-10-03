#include "libft.h"

void	ft_putnstr(char const *s, size_t len)
{
	if (s)
		ft_putnstr_fd(s, len, 1);
}