/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:02:51 by chbravo-          #+#    #+#             */
/*   Updated: 2015/12/09 12:49:14 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	char	str[12];
	int		i;

	i = 11;
	ft_bzero((void *)str, sizeof(str));
	if (nb == 0)
		str[--i] = '0';
	if (nb < 0)
	{
		while (nb != 0)
		{
			str[--i] = (char)('0' - (nb % 10));
			nb = (nb / 10);
		}
		str[--i] = '-';
	}
	else
	{
		while (nb != 0)
		{
			str[--i] = (char)('0' + (nb % 10));
			nb = (nb / 10);
		}
	}
	ft_putstr_fd(&str[i], fd);
}
