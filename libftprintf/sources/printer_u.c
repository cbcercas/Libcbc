#include <stdarg.h>
#include <inttypes.h>
#include "type.h"
#include "libft.h"
#include "utils.h"

int			ft_print_u(t_args *sarg, va_list *larg)
{
	char		*str;
	size_t	len;
	uintmax_t	nb;

	nb = ft_unsigned_from_lenght(sarg, va_arg(*larg, uintmax_t));
	if (nb == 0 && sarg->precision)
		str = ft_strnew(0);
	else
		str = ft_uimtoa(nb);
	len = ft_strlen(str);
	put_uprecision(sarg, &len, &str);
	if(!sarg->left_pad && sarg->precision_len < sarg->min_width && sarg->min_width > len)
		len += ft_print_pad(len, sarg->min_width, ' ');
	if (!(!ft_strcmp(str, "0") && sarg->precision && sarg->precision_len <= len))
		ft_putstr(str);
	if (sarg->left_pad && (sarg->min_width > 1))
	 	len += ft_print_pad(len, sarg->min_width, ' ');
	return (len);
}