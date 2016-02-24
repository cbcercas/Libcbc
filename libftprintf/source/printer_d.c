#include <stdarg.h>
#include <inttypes.h>
#include "type.h"
#include "libft.h"
#include "utils.h"

#include <stdio.h>

int ft_print_d(t_args *sarg, va_list *larg)
{
	char	*str;
	int		len;

	str = ft_imtoa(ft_signed_from_lenght(sarg, va_arg(larg, intmax_t)));
	len = ft_strlen(str) + sarg->sign_pos;
	if (!sarg->left_pad && (sarg->min_width > 1))
		len += ft_print_pad(len, sarg->min_width, sarg->zero_pad ? '0' : ' ');
	if (sarg->sign_pos == 1)
		ft_putchar('+');
	ft_putstr(str);
	if (sarg->left_pad && (sarg->min_width > 1))
		len += ft_print_pad(len, sarg->min_width, ' ');
	free(str);
	return (len);
}