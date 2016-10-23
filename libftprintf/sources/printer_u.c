#include <stdarg.h>
#include <inttypes.h>
#include "type.h"
#include "libft.h"
#include "utils.h"

static void	put_uprecision(t_args *s, unsigned int *len, char **nbr)
{
	char	*tmp;
	unsigned int l;
	unsigned int i;
	unsigned int w;

	i = 0;
	if ((s->precision_len > *len) || (s->zero_pad && s->min_width > *len && !s->left_pad))
	{
		w = (s->precision_len) ? s->precision_len : s->min_width;
		l = (s->precision)? s->precision_len - *len : s->min_width - *len;
		tmp = ft_strnew((s->precision_len)? s->precision_len : s->min_width);
		while (i < l)
			tmp[i++] = '0';
		l = 0;
		while (i < w)
			tmp[i++] = nbr[0][l++];
		free(*nbr);
		*nbr = tmp;
		*len = ft_strlen(tmp);
	}
}

int			ft_print_u(t_args *sarg, va_list *larg)
{
	char		*str;
	unsigned	len;
	uintmax_t	nb;

	nb = ft_unsigned_from_lenght(sarg, va_arg(*larg, uintmax_t));
	if (nb == 0 && sarg->precision)
		str = ft_strnew(0);
	else
		str = ft_uimtoa(nb);
	len = ft_strlen(str);
	put_uprecision(sarg, &len, &str);
	if(!sarg->left_pad && sarg->precision_len < sarg->min_width && sarg->min_width > len)
		len += ft_print_pad(len, sarg->min_width, ' ');
	if (!(!ft_strcmp(str, "0") && sarg->precision && sarg->precision_len <= len))
		ft_putstr(str);
	if (sarg->left_pad && (sarg->min_width > 1))
	 	len += ft_print_pad(len, sarg->min_width, ' ');
	return (len);
}