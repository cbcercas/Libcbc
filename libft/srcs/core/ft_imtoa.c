/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 02:58:36 by chbravo-          #+#    #+#             */
/*   Updated: 2016/11/22 23:45:49 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_countdigit(intmax_t num)
{
	int i;

	i = 0;
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

static int	ft_countdigit_unsigned(uintmax_t num)
{
	int i;

	i = 0;
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

char		*ft_imtoa(intmax_t num)
{
	char		*str;
	int			sign;
	int			i;
	intmax_t	numtmp;

	if (!(str = ft_strnew(ft_countdigit(num))))
		return (NULL);
	numtmp = num;
	if ((sign = (num < 0)))
		numtmp = -num;
	i = 0;
	if (num == 0)
		str[i++] = '0';
	while (numtmp > 0)
	{
		str[i++] = '0' + (numtmp % 10);
		numtmp /= 10;
	}
	if (sign)
		str[i++] = '-';
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}

char		*ft_uimtoa(uintmax_t num)
{
	char		*str;
	int			i;
	uintmax_t	numtmp;

	if (!(str = ft_strnew(ft_countdigit_unsigned(num) + 1)))
		return (NULL);
	numtmp = num;
	i = 0;
	if (num == 0)
		str[i++] = '0';
	while (numtmp > 0)
	{
		str[i++] = '0' + (numtmp % 10);
		numtmp /= 10;
	}
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}
