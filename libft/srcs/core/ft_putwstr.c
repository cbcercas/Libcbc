#include <wchar.h>
#include "libft.h"

void	ft_putwstr_fd(wchar_t *str, int fd)
{
	while (*str)
	{
		ft_putwchar_fd(*str, fd);
		str++;
	}
}

void	ft_putwstr(wchar_t *str)
{
		ft_putwstr_fd(str, 1);
}