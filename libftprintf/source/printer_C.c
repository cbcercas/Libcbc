#include <stdarg.h>
#include <wchar.h>
#include "libft.h"
#include "type.h"
#include "utils.h"

#include <stdio.h>

int ft_print_C(t_args *sarg, va_list *larg)
{
	size_t len;
	wchar_t c;

	c = (wchar_t)va_arg(*larg, wint_t);
	printf("c : %C\n", c);
	if (c <= 0x7F)
		len = 1;
	else if (c <= 0x7FF)
		len = 2;
	else if (c <= 0xFFFF)
		len = 3;
	else if (c <= 0x10FFFF)
		len = 4;
	else
		len = 0;
	if (!sarg->left_pad && (sarg->min_width > 1))
		len += ft_print_pad(len, sarg->min_width, ' ');
	ft_putwchar(c);
	if (sarg->left_pad && (sarg->min_width > 1))
		len += ft_print_pad(len, sarg->min_width, ' ');
	return (len);
}