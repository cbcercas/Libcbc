#include <stdarg.h>
#include "libft.h"
#include "type.h"
#include "printer.h"
#include "utils.h"
#include <wchar.h>

int	ft_print_C(t_args *sarg, va_list *larg)
{
	size_t	len;
	char *s;

	s = ft_wctostr(va_arg(*larg, wchar_t));
	len = ft_strlen(s);
	if (!sarg->left_pad && (sarg->min_width > len))
		len += ft_print_pad(len, sarg->min_width, (sarg->zero_pad) ? '0' : ' ');
	ft_putstr(s);
	if (sarg->left_pad && (sarg->min_width > 1))
		len += ft_print_pad(len, sarg->min_width, ' ');
	return (len);
}

int	ft_print_c(t_args *sarg, va_list *larg)
{
	size_t	len;

	if (sarg->len_modifier == l)
		return(ft_print_C(sarg, larg));
	else
	{
		len = 1;
		if (!sarg->left_pad && (sarg->min_width > len))
			len += ft_print_pad(len, sarg->min_width, (sarg->zero_pad) ? '0' : ' ');
		ft_putchar(va_arg(*larg, int));
		if (sarg->left_pad && (sarg->min_width > 1))
			len += ft_print_pad(len, sarg->min_width, ' ');
		return (len);
	}
}