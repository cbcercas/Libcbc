/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_def.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 02:58:21 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/15 01:33:07 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <intern/printf_type.h>
#include <intern/printf_utils.h>

int	ft_print_def(int fd, t_args *sarg, va_list *larg)
{
	size_t	len;

	(void)larg;
	len = 1;
	if (!sarg->left_pad && (sarg->min_width > 1))
		len += ft_print_pad(fd, (int)len, sarg->min_width,
							(char)((sarg->zero_pad) ? '0' : ' '));
	ft_putchar_fd(sarg->defchar, fd);
	if (sarg->left_pad && (sarg->min_width > 1))
		len += ft_print_pad(fd, (int)len, sarg->min_width, ' ');
	return ((int)len);
}
