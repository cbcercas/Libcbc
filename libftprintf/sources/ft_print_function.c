#include <stdarg.h>
#include <wchar.h>
#include "libft.h"
#include "type.h"

#include <stdio.h>

int ft_print_c(t_args *sarg, va_list *larg)
{
	printf("in ft_print_c\n");
	if (!sarg)
		return (-1);
	int c;

	c = va_arg(larg, int);
	ft_putchar(c);
	return (1);
}

int ft_print_s(t_args *sarg, va_list *larg)
{
	if (sarg->len_modifier == l)
	{
		wchar_t *str = va_arg(larg, wchar_t *);
		ft_putwstr(str);
		return (ft_wcslen(str));
	}
	else
	{
		char *str = va_arg(larg, char *);
		ft_putstr(str);
		return (ft_strlen(str));
	}
}