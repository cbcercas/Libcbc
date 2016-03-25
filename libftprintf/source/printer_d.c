#include <stdarg.h>
#include <inttypes.h>
#include "type.h"
#include "libft.h"
#include "utils.h"

#include <stdio.h>

int ft_print_d(t_args *sarg, va_list *larg)
{
	char		*str;
	int			len;
	intmax_t	nb;

	nb = ft_signed_from_lenght(sarg, va_arg(*larg, intmax_t));
	str = ft_imtoa(nb);
	len = ft_strlen(str);
	if (!sarg->left_pad && (sarg->min_width > 1))
		len += ft_print_pad(len, sarg->min_width, sarg->zero_pad ? '0' : ' ');
	if ((sarg->sign_pos || sarg->blank_pos) && nb >= 0)
	{
		ft_putchar((sarg->sign_pos ? '+' : ' '));
		len++;
	}
	ft_putstr(str);
	if (sarg->left_pad && (sarg->min_width > 1))
		len += ft_print_pad(len, sarg->min_width, ' ');
	free(str);
	return (len);
}