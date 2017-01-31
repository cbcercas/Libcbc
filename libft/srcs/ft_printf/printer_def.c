/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_def.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 02:58:21 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/31 18:43:01 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <ft_printf/printf_type.h>
#include <ft_printf/printf_utils.h>

int	ft_print_def(int fd, t_args *sarg, va_list *larg)
{
	size_t	len;

	(void)larg;
	len = 1;
	if (!sarg->left_pad && (sarg->min_width > 1))
		len += ft_print_pad(fd, len, sarg->min_width, (sarg->zero_pad) ? '0' : ' ');
	ft_putchar_fd(sarg->defchar, fd);
	if (sarg->left_pad && (sarg->min_width > 1))
		len += ft_print_pad(fd, len, sarg->min_width, ' ');
	return (len);
}
