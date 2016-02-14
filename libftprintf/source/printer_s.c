#include <stdarg.h>
#include "libft.h"
#include "type.h"
#include "printer.h"
#include "utils.h"

#include <stdio.h>

int ft_print_s(t_args *sarg, va_list *larg)
{
	char *str;
	size_t len;

	if (sarg->len_modifier == l)
		return(ft_print_S(sarg, larg));
	else
	{
		str = va_arg(larg, char *);
		len = ft_strlen(str);
		if (!sarg->left_pad && (sarg->min_width > len))
			len += ft_print_pad(len, sarg->min_width, ' ');
		ft_putstr(str);
		if (sarg->left_pad && (sarg->min_width > len))
			len += ft_print_pad(len, sarg->min_width, ' ');
		return (len);
	}
}