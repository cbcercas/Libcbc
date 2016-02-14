#include <stdarg.h>
#include <wchar.h>
#include "libft.h"
#include "type.h"
#include "printer.h"
#include "utils.h"

#include <stdio.h>

int ft_print_c(t_args *sarg, va_list *larg)
{
	size_t len;

	if (sarg->len_modifier == l)
	{
		return(ft_print_C(sarg, larg));
	}
	else
	{
		len = 1;
		if (!sarg->left_pad && (sarg->min_width > 1))
			len += ft_print_pad(len, sarg->min_width, ' ');
		ft_putchar(va_arg(*larg, int));
		if (sarg->left_pad && (sarg->min_width > 1))
			len += ft_print_pad(len, sarg->min_width, ' ');
		return (len);
	}
}