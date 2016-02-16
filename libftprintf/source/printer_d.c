#include <stdarg.h>
#include <inttypes.h>
#include "type.h"
#include "libft.h"

#include <stdio.h>

int ft_print_d(t_args *sarg, va_list *larg)
{
	printf("If printer_d\n");
	intmax_t	nb;
	char	*str;
	int		len;

	nb = va_arg(larg, intmax_t);
	if (sarg->len_modifier == h)
		str = ft_stoa((short)nb);
	else if (sarg->len_modifier == l)
		str = ft_ltoa((long)nb);
	else if (sarg->len_modifier == ll)
		str = ft_lltoa((long long)nb);
	else
	{
		printf("other\n");
		str = ft_itoa((int)nb);
	}
	len = ft_strlen(str);
	ft_putstr(str);
	//free(str);
	return (len);
}