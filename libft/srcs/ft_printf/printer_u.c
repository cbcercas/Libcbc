/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 02:58:21 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/31 18:43:33 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <inttypes.h>
#include <libft.h>
#include <ft_printf/printf_type.h>
#include <ft_printf/printf_utils.h>

int			ft_print_u(int fd, t_args *sarg, va_list *larg)
{
	char		*str;
	size_t		len;
	uintmax_t	nb;

	nb = ft_unsigned_from_lenght(sarg, va_arg(*larg, uintmax_t));
	if (nb == 0 && sarg->precision)
		str = ft_strnew(0);
	else
		str = ft_uimtoa(nb);
	len = ft_strlen(str);
	put_uprecision(sarg, &len, &str);
	if (!sarg->left_pad && sarg->preci_len < sarg->min_width
		&& sarg->min_width > len)
		len += ft_print_pad(fd, len, sarg->min_width, ' ');
	if (!(!ft_strcmp(str, "0") && sarg->precision
		&& sarg->preci_len <= len))
		ft_putstr_fd(str, fd);
	if (sarg->left_pad && (sarg->min_width > 1))
		len += ft_print_pad(fd, len, sarg->min_width, ' ');
	ft_strdel(&str);
	return (len);
}
