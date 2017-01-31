/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 03:28:33 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/31 18:42:46 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <ft_printf/printf_type.h>
#include <ft_printf/printer.h>
#include <ft_printf/printf_utils.h>
#include <wchar.h>

int	ft_print_wc(int fd, t_args *sarg, va_list *larg)
{
	size_t	len;
	size_t	len_save;
	char	*s;

	s = ft_wctostr(va_arg(*larg, wchar_t));
	len = ft_strlen(s);
	len_save = len;
	len = (len != 0) ? len : 1;
	if (!sarg->left_pad && (sarg->min_width > len))
		len += ft_print_pad(fd, len, sarg->min_width, (sarg->zero_pad) ? '0' : ' ');
	len_save ? ft_putstr_fd(s, fd) : write(1, "\0", 1);
	ft_strdel(&s);
	if (sarg->left_pad && (sarg->min_width > 1))
		len += ft_print_pad(fd, len, sarg->min_width, ' ');
	return (len);
}

int	ft_print_c(int fd, t_args *sarg, va_list *larg)
{
	size_t	len;

	if (sarg->len_modifier == l)
		return (ft_print_wc(fd, sarg, larg));
	else
	{
		len = 1;
		if (!sarg->left_pad && (sarg->min_width > len))
			len += ft_print_pad(fd, len, sarg->min_width,
				(sarg->zero_pad) ? '0' : ' ');
		ft_putchar_fd(va_arg(*larg, int), fd);
		if (sarg->left_pad && (sarg->min_width > 1))
			len += ft_print_pad(fd, len, sarg->min_width, ' ');
		return (len);
	}
}
