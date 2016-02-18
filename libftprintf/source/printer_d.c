#include <stdarg.h>
#include <inttypes.h>
#include "type.h"
#include "libft.h"
#include "utils.h"

#include <stdio.h>
static char *ft_dtoa(intmax_t nb)
{
	if (sarg->len_modifier == h)
		return (ft_stoa((short)nb));
	else if (sarg->len_modifier == l)
		return (ft_ltoa((long)nb));
	else if (sarg->len_modifier == ll)
		return (ft_lltoa((long long)nb));
	else if (sarg->len_modifier == j)
		return (ft_imtoa(nb));
	else if (sarg->len_modifier == z)
		return (ft_sttoa((size_t)nb));
	else
		return (ft_itoa((int)nb));
}
int ft_print_d(t_args *sarg, va_list *larg)
{
	char	*str;
	int		len;

	str = ft_dtoa(va_arg(larg, intmax_t));
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