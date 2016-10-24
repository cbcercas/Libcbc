#include <stdarg.h>
#include "type.h"
#include "libft.h"
#include "utils.h"

int ft_print_X(t_args *s, va_list *larg)
{
	char		*str;
	size_t		len;
	uintmax_t	unb;

	unb = ft_unsigned_from_lenght(s, va_arg(*larg, uintmax_t));
	str = (ft_uitohex(unb, 1));
	len = (s->precision && !s->precision_len && unb == 0) ? 0 : ft_strlen(str);
	put_uprecision(s, &len, &str);
	if (s->alternate && ft_strncmp(str, "0\0", 2))
		len += 2;
	if (ft_strncmp(str, "0\0", 2) && s->alternate && s->zero_pad && unb > 0)
		ft_putstr("0X");
	if (!s->left_pad && (s->min_width > 1))
		len += ft_print_pad(len, s->min_width, s->zero_pad ? '0' : ' ');
	if (ft_strncmp(str, "0\0", 2) && s->alternate && !s->zero_pad && unb > 0)
		ft_putstr("0X");
	(s->precision && !s->precision_len && unb == 0) ? 0 : ft_putstr(str);
	if (s->left_pad && (s->min_width > 1))
		len += ft_print_pad(len, s->min_width, ' ');
	free(str);
	return (len);
}

int ft_print_x(t_args *s, va_list *larg)
{
	char		*str;
	size_t		len;
	uintmax_t	unb;

	unb = ft_unsigned_from_lenght(s, va_arg(*larg, uintmax_t));
	str = (ft_uitohex(unb, 0));
	len = (s->precision && !s->precision_len && unb == 0) ? 0 : ft_strlen(str);
	put_uprecision(s, &len, &str);
	if ((s->alternate && ft_strncmp(str, "0\0", 2)) || s->conversion == (enum conv)p)
		len += 2;
	if ((ft_strncmp(str, "0\0", 2) && s->alternate && s->zero_pad && unb > 0) 
			|| (s->conversion == (enum conv)p && s->zero_pad))
		ft_putstr("0x");
	if (!s->left_pad && (s->min_width > 1))
		len += ft_print_pad(len, s->min_width, s->zero_pad ? '0' : ' ');
	if ((ft_strncmp(str, "0\0", 2) && s->alternate && !s->zero_pad && unb > 0) 
			|| (s->conversion == (enum conv)p && !s->zero_pad))
		ft_putstr("0x");
	(s->precision && !s->precision_len && unb == 0) ? 0 : ft_putstr(str);
	if (s->left_pad && (s->min_width > 1))
		len += ft_print_pad(len, s->min_width, ' ');
	free(str);
	return (len);
}
