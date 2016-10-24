#include <stdarg.h>
#include <wchar.h>
#include "libft.h"
#include "type.h"
#include "printer.h"
#include "utils.h"

int	ft_print_S(t_args *sarg, va_list *larg)
{
	wchar_t	*ws;
	char	*s;
	size_t	len;

	ws = va_arg(*larg, wchar_t *);
	s = ft_wstostr(ws);
	s = (!s) ? ft_strdup("(null)") : s;
	len = sarg->precision ? sarg->precision_len : ft_strlen(s);
	if (!sarg->left_pad && (sarg->min_width > len))
		len += ft_print_pad(len, sarg->min_width, ' ');
	ft_putstr(s);
	free(s);
	if (sarg->left_pad && (sarg->min_width > len))
		len += ft_print_pad(len, sarg->min_width, ' ');
	return (len);
}

int	ft_print_s(t_args *sarg, va_list *larg)
{
	char	*s;
	size_t	len;
	size_t	len_save;
	int		free;

	if (sarg->len_modifier == l)
		return(ft_print_S(sarg, larg));
	s = va_arg(*larg, char *);
	free = (!s) ? 1 : 0;
	s = (!s) ? ft_strdup("(null)") : s;
	len = ft_strlen(s);
	if (sarg->precision && sarg->precision < len)
		len = sarg->precision_len;
	len_save = len;
	if (!sarg->left_pad && (sarg->min_width > len))
		len += ft_print_pad(len, sarg->min_width, ' ');
	ft_putnstr(s, len_save);
	(free) ? ft_strdel((char**)&s) : 0;
	if (sarg->left_pad && (sarg->min_width > len))
		len += ft_print_pad(len, sarg->min_width, ' ');
	return (len);
}