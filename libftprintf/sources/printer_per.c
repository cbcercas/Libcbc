#include "libft.h"
#include "type.h"
#include "utils.h"

int	ft_print_per(t_args *sarg)
{
	size_t	len;

	len = 1;
	if (!sarg->left_pad && (sarg->min_width > 1))
			len += ft_print_pad(len, sarg->min_width, ' ');
	ft_putchar('%');
	if (sarg->left_pad && (sarg->min_width > 1))
			len += ft_print_pad(len, sarg->min_width, ' ');
	return (len);
}