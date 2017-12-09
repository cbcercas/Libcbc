/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 03:37:55 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/31 18:43:40 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <intern/printf_type.h>
#include <intern/printf_utils.h>
#include <libft.h>

int	ft_print_wx(int fd, t_args *s, va_list *larg)
{
	char		*str;
	size_t		len;
	uintmax_t	unb;

	unb = ft_unsigned_from_lenght(s, va_arg(*larg, uintmax_t));
	str = (ft_uitohex(unb, 1));
	len = (s->precision && !s->preci_len && unb == 0) ? 0 : ft_strlen(str);
	(s->precision) ?
		put_uprecision(s, &len, &str) : 0;
	if (s->alternate && ft_strncmp(str, "0\0", 2))
		len += 2;
	if (ft_strncmp(str, "0\0", 2) && s->alternate && s->zero_pad && unb > 0)
		ft_putstr_fd("0X", fd);
	if (!s->left_pad && (s->min_width > 1))
		len += ft_print_pad(fd, (int) len, s->min_width,
							(char) (s->zero_pad ? '0' : ' '));
	if (ft_strncmp(str, "0\0", 2) && s->alternate && !s->zero_pad && unb > 0)
		ft_putstr_fd("0X", fd);
	(s->precision && !s->preci_len && unb == 0) ? 0 : ft_putstr(str);
	if (s->left_pad && (s->min_width > 1))
		len += ft_print_pad(fd, (int) len, s->min_width, ' ');
	ft_strdel(&str);
	return (int) (len);
}

int	ft_print_x(int fd, t_args *s, va_list *larg)
{
	char		*str;
	size_t		len;
	uintmax_t	unb;

	unb = ft_unsigned_from_lenght(s, va_arg(*larg, uintmax_t));
	str = (ft_uitohex(unb, 0));
	len = (s->precision && !s->preci_len && unb == 0) ? 0 : ft_strlen(str);
	(s->precision) ?
		put_uprecision(s, &len, &str) : 0;
	if ((s->alternate && ft_strncmp(str, "0\0", 2))
		|| s->conversion == p)
		len += 2;
	if ((ft_strncmp(str, "0\0", 2) && s->alternate && s->zero_pad && unb > 0)
			|| (s->conversion == p && s->zero_pad))
		ft_putstr_fd("0x", fd);
	if (!s->left_pad && (s->min_width > 1))
		len += ft_print_pad(fd, (int) len, s->min_width,
							(char) (s->zero_pad ? '0' : ' '));
	if ((ft_strncmp(str, "0\0", 2) && s->alternate && !s->zero_pad && unb > 0)
			|| (s->conversion == p && !s->zero_pad))
		ft_putstr_fd("0x", fd);
	(s->precision && !s->preci_len && unb == 0) ? 0 : ft_putstr(str);
	if (s->left_pad && (s->min_width > 1))
		len += ft_print_pad(fd, (int) len, s->min_width, ' ');
	ft_strdel(&str);
	return (int) (len);
}
