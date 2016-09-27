/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:02:51 by chbravo-          #+#    #+#             */
/*   Updated: 2015/12/09 13:14:25 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int sign;
	int i;
	int nbr;

	sign = 0;
	i = 0;
	nbr = 0;
	while ((((*str == '-') || (*str == '+')) && ft_isdigit(str[1]))
		|| ft_iswhitespace(*str))
	{
		if (*str == '-')
		{
			sign = 1;
			if (!(ft_isdigit(str[1])))
				return (0);
		}
		str++;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
		nbr = (nbr * 10) + (str[i++] - 48);
	if (sign)
		nbr = -nbr;
	return (nbr);
}
