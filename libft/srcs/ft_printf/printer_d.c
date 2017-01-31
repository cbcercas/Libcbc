/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 02:58:21 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/31 18:42:55 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <inttypes.h>
#include <ft_printf/printf_type.h>
#include <ft_printf/printf_utils.h>
#include <libft.h>

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

static void	put_sign(char *sign, t_args *s, unsigned int *len, char **nbr)
{
	char	*tmp;

	if (s->sign_pos || *sign == '-')
	{
		tmp = ft_strjoin((*sign == '-') ? "-" : "+", *nbr);
		ft_strdel(nbr);
		*nbr = tmp;
		*len += 1;
	}
	else if (s->blank_pos)
	{
		tmp = ft_strjoin(" ", *nbr);
		ft_strdel(nbr);
		*nbr = tmp;
		*len += 1;
	}
}

static void	put_precision(t_args *s, unsigned int *len, char **nbr, char *sign)
{
	char			*tmp;
	unsigned int	l;
	unsigned int	i;
	unsigned int	w;

	i = 0;
	if ((s->preci_len > *len)
		|| (s->zero_pad && s->min_width > *len && !s->left_pad))
	{
		w = (s->preci_len) ? s->preci_len : s->min_width;
		l = (s->precision) ? s->preci_len - *len : s->min_width - *len;
		tmp = ft_strnew((s->preci_len) ? s->preci_len : s->min_width);
		if (!s->precision && (*sign == '-' || (*sign == '+'
				&& (s->blank_pos || s->sign_pos))))
			l--;
		while (i < l)
			tmp[i++] = '0';
		l = 0;
		while (i < w)
			tmp[i++] = nbr[0][l++];
		ft_strdel(nbr);
		*nbr = tmp;
		*len = ft_strlen(tmp);
	}
}

int			ft_print_d(int fd, t_args *sarg, va_list *larg)
{
	char		*str;
	char		sign;
	unsigned	len;

	str = ft_get_nbstr(sarg, larg, &sign);
	len = ft_strlen(str);
	put_precision(sarg, &len, &str, &sign);
	put_sign(&sign, sarg, &len, &str);
	if (!sarg->left_pad
		&& sarg->preci_len < sarg->min_width && sarg->min_width > len)
		len += ft_print_pad(fd, len, sarg->min_width, ' ');
	if (!(!ft_strcmp(str, "0")
		&& sarg->precision && sarg->preci_len <= len))
		ft_putstr_fd(str, fd);
	if (sarg->left_pad && (sarg->min_width > 1))
		len += ft_print_pad(fd, len, sarg->min_width, ' ');
	ft_strdel(&str);
	return (len);
}
