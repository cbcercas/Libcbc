#include <stdarg.h>
#include <inttypes.h>
#include "type.h"
#include "libft.h"
#include "utils.h"

#include <stdio.h>

static char	*ft_get_nbstr(t_args *sarg, va_list *larg, char *sign)
{
	intmax_t	nb;
	uintmax_t	unb;

	*sign = '+';
	nb = ft_signed_from_lenght(sarg, va_arg(*larg, intmax_t));
	if (nb < 0)
	{
		unb = (uintmax_t)-nb;
		*sign = '-';
	}
	else
		unb = (uintmax_t)nb;
	return (ft_uimtoa(unb));
}


int ft_print_d(t_args *sarg, va_list *larg)
{
	char		*str;
	char		sign;
	int			len;

	str = ft_get_nbstr(sarg, larg, &sign);
	len = ft_strlen(str) + (sign == '-' ? 1 : 0);
	if (!sarg->left_pad && (sarg->min_width > 1))
	{
		if ((sarg->sign_pos || sarg->blank_pos || sign == '-') && sarg->zero_pad)
		{
			ft_putchar((sarg->sign_pos || sign == '-' ? sign : ' '));
			len += (sign == '-' ? 0 : 1);
		}
		len += ft_print_pad(len, sarg->min_width, sarg->zero_pad ? '0' : ' ');
		if ((sarg->sign_pos || sarg->blank_pos || sign == '-') && !sarg->zero_pad)
		{
			ft_putchar((sarg->sign_pos || sign == '-' ? sign : ' '));
			len += (sign == '-' ? 0 : 1);
		}
	} else if ((sarg->sign_pos || sarg->blank_pos || sign == '-'))
	{
		ft_putchar((sarg->sign_pos || sign == '-' ? sign : ' '));
		len += (sign == '-' ? 0 : 1);
	}
	ft_putstr(str);
	if (sarg->left_pad && (sarg->min_width > 1))
		len += ft_print_pad(len, sarg->min_width, ' ');
	free(str);
	return (len);
}