#include <stdarg.h>
#include "type.h"
#include "libft.h"
#include "utils.h"

int ft_print_o(t_args *sarg, va_list *larg)
{
	char		*str;
	size_t		len;
	uintmax_t	nb;

	nb = ft_unsigned_from_lenght(sarg, va_arg(*larg, uintmax_t));
	str = ft_uitooctal(nb, (sarg->alternate && nb != 0) ? 1 : 0);
	len = ft_strlen(str);
	put_uprecision(sarg, &len, &str);
	if (!sarg->left_pad && (sarg->min_width > 1))
		len += ft_print_pad(len, sarg->min_width, sarg->zero_pad ? '0' : ' ');
	if(sarg->precision && !sarg->precision_len && nb == 0 && !sarg->alternate)
		len = 0;
	else
		ft_putstr(str);
	if (sarg->left_pad && (sarg->min_width > 1))
		len += ft_print_pad(len, sarg->min_width, ' ');
	free(str);
	return (len);
}
