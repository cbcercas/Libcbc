/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:02:51 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/19 03:09:12 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isprint(int nb)
{
	if (nb >= 32 && nb <= 126)
		return (1);
	return (0);
}

BOOL	ft_isprintstr(char const *str)
{
	while (str && ft_isprint(*str))
		str++;
	return (*str != '\0') ? false : true;
}
