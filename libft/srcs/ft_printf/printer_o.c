/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 02:58:21 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/31 18:43:09 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <ft_printf/printf_type.h>
#include <ft_printf/printf_utils.h>
#include <libft.h>

int	ft_print_o(int fd, t_args *sarg, va_list *larg)
{
	char		*str;
	size_t		len;
	uintmax_t	nb;

	nb = ft_unsigned_from_lenght(sarg, va_arg(*larg, uintmax_t));
	str = ft_uitooctal(nb, (sarg->alternate && nb != 0) ? 1 : 0);
	len = ft_strlen(str);
	(sarg->precision && nb != 0) ?
		put_uprecision(sarg, &len, &str) : 0;
	if (!sarg->left_pad && (sarg->min_width > 1))
		len += ft_print_pad(fd, len, sarg->min_width, sarg->zero_pad ? '0' : ' ');
	if (sarg->precision && !sarg->preci_len && nb == 0 && !sarg->alternate)
		(sarg->min_width) ? ft_putchar_fd(' ', fd) : len--;
	else
		ft_putstr_fd(str, fd);
	if (sarg->left_pad && (sarg->min_width > 1))
		len += ft_print_pad(fd, len, sarg->min_width, ' ');
	ft_strdel(&str);
	return (len);
}
