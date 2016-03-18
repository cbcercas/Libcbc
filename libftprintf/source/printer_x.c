#include <stdarg.h>
#include "type.h"
#include "libft.h"
#include "utils.h"

int ft_print_X(t_args *sarg, va_list *larg)
{
	char	*str;
	int		len;
	uintmax_t nb;

	if (!sarg)
		return -1;
	nb = ft_unsigned_from_lenght(sarg, va_arg(*larg, uintmax_t));
	str = (ft_uitohex(nb, 1));
	len = ft_strlen(str);
	if (!sarg->left_pad && (sarg->min_width > 1))
		len += ft_print_pad(len, sarg->min_width, sarg->zero_pad ? '0' : ' ');
	ft_putstr(str);
	if (sarg->left_pad && (sarg->min_width > 1))
		len += ft_print_pad(len, sarg->min_width, ' ');
	free(str);
	return (len);
}

int ft_print_x(t_args *sarg, va_list *larg)
{
	char	*str;
	int		len;
	uintmax_t unb;

	if (!sarg)
		return -1;
	unb = ft_unsigned_from_lenght(sarg, va_arg(*larg, uintmax_t));
	str = (ft_uitohex(unb, 0));
	len = ft_strlen(str);
	if (!sarg->left_pad && (sarg->min_width > 1))
		len += ft_print_pad(len, sarg->min_width, sarg->zero_pad ? '0' : ' ');
	ft_putstr(str);
	if (sarg->left_pad && (sarg->min_width > 1))
		len += ft_print_pad(len, sarg->min_width, ' ');
	free(str);
	return (len);
}
