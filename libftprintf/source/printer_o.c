#include <stdarg.h>
#include "type.h"
#include "libft.h"
#include "utils.h"

#include <stdio.h>



char	*ft_itoo(uintmax_t nb)
{
	uintmax_t rst;
	uintmax_t i=1;
	uintmax_t ret = 0;
    while (nb != 0)
    {
        rst = nb%8;
        nb /= 8;
        ret += rst*i;
        i *= 10;
    }
	return (ft_uimtoa(ret));
}

int ft_print_o(t_args *sarg, va_list *larg)
{
	char	*str;
	int		len;
	if (!sarg)
		return -1;
	str = (ft_itoo(ft_unsigned_from_lenght(sarg, va_arg(larg, uintmax_t))));
	len = ft_strlen(str);
	if (!sarg->left_pad && (sarg->min_width > 1))
		len += ft_print_pad(len, sarg->min_width, sarg->zero_pad ? '0' : ' ');
	ft_putstr(str);
	if (sarg->left_pad && (sarg->min_width > 1))
		len += ft_print_pad(len, sarg->min_width, ' ');
	free(str);
	return (len);
}