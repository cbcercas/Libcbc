/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 02:58:36 by chbravo-          #+#    #+#             */
/*   Updated: 2016/11/18 11:49:16 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr_fd(char const *s, size_t len, int fd)
{
	if (s)
		write(fd, s, len);
}

void	ft_putnstr(char const *s, size_t len)
{
	if (s)
		ft_putnstr_fd(s, len, 1);
}
