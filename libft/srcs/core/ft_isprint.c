/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:02:51 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/19 05:43:20 by chbravo-         ###   ########.fr       */
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
	return (str && *str != '\0') ? false : true;
}
