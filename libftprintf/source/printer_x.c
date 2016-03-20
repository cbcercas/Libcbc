#include <stdarg.h>
#include "type.h"
#include "libft.h"
#include "utils.h"

int ft_print_X(t_args *sarg, va_list *larg)
{
	char	*str;
	int		len;
	uintmax_t unb;

	unb = ft_unsigned_from_lenght(sarg, va_arg(*larg, uintmax_t));
	str = (ft_uitohex(unb, 1));
	len = ft_strlen(str);
	if (sarg->alternate && ft_strncmp(str, "0\0", 2))
		len += 2;
	if (ft_strncmp(str, "0\0", 2) && sarg->alternate && sarg->zero_pad)
		ft_putstr("0X");
	if (!sarg->left_pad && (sarg->min_width > 1))
		len += ft_print_pad(len, sarg->min_width, sarg->zero_pad ? '0' : ' ');
	if (ft_strncmp(str, "0\0", 2) && sarg->alternate && !sarg->zero_pad)
		ft_putstr("0X");
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

	unb = ft_unsigned_from_lenght(sarg, va_arg(*larg, uintmax_t));
	str = (ft_uitohex(unb, 0));
	len = ft_strlen(str);
	if (sarg->alternate && ft_strncmp(str, "0\0", 2))
		len += 2;
	if (ft_strncmp(str, "0\0", 2) && sarg->alternate && sarg->zero_pad)
		ft_putstr("0x");
	if (!sarg->left_pad && (sarg->min_width > 1))
		len += ft_print_pad(len, sarg->min_width, sarg->zero_pad ? '0' : ' ');
	if (ft_strncmp(str, "0\0", 2) && sarg->alternate && !sarg->zero_pad)
		ft_putstr("0x");
	ft_putstr(str);
	if (sarg->left_pad && (sarg->min_width > 1))
		len += ft_print_pad(len, sarg->min_width, ' ');
	free(str);
	return (len);
}
