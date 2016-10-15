#include <stdarg.h>
#include "type.h"
#include "libft.h"
#include "utils.h"

int ft_print_o(t_args *sarg, va_list *larg)
{
	char	*str;
	int		len;
	uintmax_t nb;
	if (!sarg)
		return -1;
	nb = ft_unsigned_from_lenght(sarg, va_arg(*larg, uintmax_t));
	str = ft_uitooctal(nb, (sarg->precision && !sarg->precision_len) ? 0 : sarg->alternate);
	len = (sarg->precision && !sarg->precision_len && nb == 0 && !sarg->alternate) ? 0 : ft_strlen(str);
	if (!sarg->left_pad && (sarg->min_width > 1))
		len += ft_print_pad(len, sarg->min_width, sarg->zero_pad ? '0' : ' ');
	while (sarg->precision && sarg->precision_len > (unsigned)len)
	{
		ft_putchar('0');
		len++;
	}
	(sarg->precision && !sarg->precision_len && nb == 0 && !sarg->alternate) ? 0 : ft_putstr(str);
	if (sarg->left_pad && (sarg->min_width > 1))
		len += ft_print_pad(len, sarg->min_width, ' ');
	free(str);
	return (len);
}
