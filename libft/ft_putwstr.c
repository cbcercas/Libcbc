#include <wchar.h>
#include "libft.h"

void	ft_putwstr(wchar_t *str)
{
		ft_putwstr_fd(str, 1);
}