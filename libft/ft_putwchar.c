#include <wchar.h>
#include "libft.h"

void	ft_putwchar(wchar_t c)
{
	ft_putwchar_fd(c, 1);
}