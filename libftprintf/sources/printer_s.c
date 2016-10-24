#include <stdarg.h>
#include <wchar.h>
#include "libft.h"
#include "type.h"
#include "printer.h"
#include "utils.h"

static char	*ft_nwstostr(wchar_t *ws, size_t len)
{
	char	*s;
	char	*s2;
	int i;

	if (!ws)
		return (NULL);
	i = 0;
	s = ft_strnew(0);
	s2 = NULL;
	while (ws[i] && ft_strlen(s) <= len)
	{
		ft_strdel((char**)&s2);
		s2 = ft_strdup(s);
		s = ft_strjoincl(s, ft_wctostr(ws[i++]), 3);
	}
	ft_strdel((char**)&s);
	return (s2);
}

int	ft_print_S(t_args *sarg, va_list *larg)
{
	wchar_t	*ws;
	char	*s;
	size_t	len;
	size_t	len_save;

	ws = va_arg(*larg, wchar_t *);
	s = (sarg->precision && sarg->precision_len) ? ft_nwstostr(ws, sarg->precision_len) : ft_wstostr(ws);
	s = (!s) ? ft_strdup("(null)") : ft_strdup(s);
	len = ft_strlen(s);
	if (sarg->precision && sarg->precision_len < len)
		len = sarg->precision_len;
	len_save = len;
	if (!sarg->left_pad && (sarg->min_width > len))
		len += ft_print_pad(len, sarg->min_width, (sarg->zero_pad) ? '0' : ' ');
	ft_putnstr(s, len_save);
	ft_strdel((char**)&s);
	if (sarg->left_pad && (sarg->min_width > len))
		len += ft_print_pad(len, sarg->min_width, ' ');
	return (len);
}

int	ft_print_s(t_args *sarg, va_list *larg)
{
	char	*s;
	size_t	len;
	size_t	len_save;

	if (sarg->len_modifier == l)
		return(ft_print_S(sarg, larg));
	s = va_arg(*larg, char *);
	s = (!s) ? ft_strdup("(null)") : ft_strdup(s);
	len = ft_strlen(s);
	if (sarg->precision && sarg->precision_len < len)
		len = sarg->precision_len;
	len_save = len;
	if (!sarg->left_pad && (sarg->min_width > len))
		len += ft_print_pad(len, sarg->min_width, (sarg->zero_pad) ? '0' : ' ');
	ft_putnstr(s, len_save);
	ft_strdel((char**)&s);
	if (sarg->left_pad && (sarg->min_width > len))
		len += ft_print_pad(len, sarg->min_width, ' ');
	return (len);
}