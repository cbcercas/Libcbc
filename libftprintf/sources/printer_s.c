#include <stdarg.h>
#include <wchar.h>
#include "libft.h"
#include "type.h"
#include "printer.h"
#include "utils.h"

#include <stdio.h>

int	ft_print_S(t_args *sarg, va_list *larg)
{
	wchar_t	*str;
	size_t	len;

	str = va_arg(*larg, wchar_t *);
	len = sarg->precision ? sarg->precision_len : ft_wcslen(str);
	if (!sarg->left_pad && (sarg->min_width > len))
		len += ft_print_pad(len, sarg->min_width, ' ');
	ft_putwstr(str);
	if (sarg->left_pad && (sarg->min_width > len))
		len += ft_print_pad(len, sarg->min_width, ' ');
	return (len);
}

int	ft_print_s(t_args *sarg, va_list *larg)
{
	char	*str;
	size_t	len;
	size_t	len_save;

	if (sarg->len_modifier == l)
		return(ft_print_S(sarg, larg));
	else
	{
		str = va_arg(*larg, char *);
		if (str)
			len = ft_strlen(str);
		else
			len = 6;
		if (sarg->precision && sarg->precision < len)
			len = sarg->precision_len;
		len_save = len;
		if (!sarg->left_pad && (sarg->min_width > len))
			len += ft_print_pad(len, sarg->min_width, ' ');
		str == NULL ? ft_putnstr("(null)", len_save) : ft_putnstr(str, len_save);
		if (sarg->left_pad && (sarg->min_width > len))
			len += ft_print_pad(len, sarg->min_width, ' ');
		return (len);
	}
}