/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 20:21:26 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/13 21:17:32 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <ft_printf/printf_type.h>
#include <ft_printf/printf_utils.h>
#include <ft_printf/libftprintf.h>

int		ft_dprintf(int fd, const char *fmt, ...)
{
	int		ret;
	va_list larg;

	va_start(larg, fmt);
	ret = ft_print(fd, &larg, fmt, 0);
	return (ret);
}

int		ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	int		ret;
	va_list	larg;

	va_copy(larg, ap);
	ret = ft_print(fd, &larg, fmt, 0);
	return (ret);
}
