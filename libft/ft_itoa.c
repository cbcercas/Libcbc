/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:02:51 by chbravo-          #+#    #+#             */
/*   Updated: 2015/12/09 13:04:59 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strrev(char *str)
{
	char	c;
	int		i;
	int		len;

	len = ft_strlen(str) - 1;
	i = 0;
	while (i < len)
	{
		c = str[len];
		str[len] = str[i];
		str[i] = c;
		len--;
		i++;
	}
	return (str);
}

char		*ft_itoa(int num)
{
	char	*str;
	int		sign;
	int		i;
	int		numtmp;

	if (!(str = ft_strnew(ft_countchiffres(num))))
		return (NULL);
	if (num == -2147483648)
		ft_strcpy(str, "8463847412-");
	else
	{
		sign = (num < 0);
		numtmp = ((num < 0)) ? -num : num;
		i = 0;
		(num == 0) ? str[i++] = '0' : 0;
		while (numtmp > 0)
		{
			str[i++] = '0' + (numtmp % 10);
			numtmp /= 10;
		}
		if (sign)
			str[i++] = '-';
		str[i] = '\0';
	}
	return (ft_strrev(str));
}
