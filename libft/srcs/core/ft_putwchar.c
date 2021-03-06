/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 02:58:36 by chbravo-          #+#    #+#             */
/*   Updated: 2016/11/18 11:46:26 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "libft.h"

void	ft_putwchar_fd(wchar_t c, int fd)
{
	if (c <= 0x7F)
		ft_putchar_fd((char)c, fd);
	else if (c <= 0x7FF)
	{
		ft_putchar_fd((char)((c >> 6) + 0xC0), fd);
		ft_putchar_fd((char)((c & 0x3F) + 0x80), fd);
	}
	else if (c <= 0xFFFF)
	{
		ft_putchar_fd((char)((c >> 12) + 0xE0), fd);
		ft_putchar_fd((char)(((c >> 6) & 0x3F) + 0x80), fd);
		ft_putchar_fd((char)((c & 0x3F) + 0x80), fd);
	}
	else if (c <= 0x10FFFF)
	{
		ft_putchar_fd((char)((c >> 18) + 0xF0), fd);
		ft_putchar_fd((char)(((c >> 12) & 0x3F) + 0x80), fd);
		ft_putchar_fd((char)(((c >> 6) & 0x3F) + 0x80), fd);
		ft_putchar_fd((char)((c & 0x3F) + 0x80), fd);
	}
}

void	ft_putwchar(wchar_t c)
{
	ft_putwchar_fd(c, 1);
}
