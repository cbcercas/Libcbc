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
	if (unb == 0 && sarg->precision)
		return (ft_strnew(0));
	return (ft_uimtoa(unb));
}

static void	put_sign(char *sign, t_args *s, unsigned  int *len, char **nbr)
{
	char	*tmp;

	if (s->sign_pos || *sign == '-')
	{
		tmp = ft_strjoin((*sign == '-') ? "-" : "+", *nbr);
		free(*nbr);
		*nbr = tmp;
		*len += 1;
	}
	else if (s->blank_pos)
	{
		tmp = ft_strjoin(" ", *nbr);
		free(*nbr);
		*nbr = tmp;
		*len += 1;
	}
}

static void	put_precision(t_args *s, unsigned int *len, char **nbr, char *sign)
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
		if (s->zero_pad && !s->precision)
			l -= (*sign == '-' || s->sign_pos) ? 1 : 0;
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

int			ft_print_d(t_args *sarg, va_list *larg)
{
	char		*str;
	char		sign;
	unsigned	len;

	str = ft_get_nbstr(sarg, larg, &sign);
	len = ft_strlen(str);
	put_precision(sarg, &len, &str, &sign);
	put_sign(&sign, sarg, &len, &str);
	if(!sarg->left_pad && sarg->precision_len < sarg->min_width && sarg->min_width > len)
		len += ft_print_pad(len, sarg->min_width, ' ');
	if (!(!ft_strcmp(str, "0") && sarg->precision && sarg->precision_len <= len))
		ft_putstr(str);
	if (sarg->left_pad && (sarg->min_width > 1))
	 	len += ft_print_pad(len, sarg->min_width, ' ');
	return (len);
}
