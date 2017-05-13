/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 20:17:44 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/13 20:18:09 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_uitoa_base(unsigned long long nb, int base)
{
	char					*str;
	int						size;
	unsigned long long		s;

	size = 1;
	s = nb;
	while (nb > (unsigned long long int)base - 1)
	{
		nb = nb / base;
		size++;
	}
	if (!(str = (char *)malloc(sizeof(*str) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	while (size--)
	{
		str[size] = (s % base < 10) ? (s % base) + '0' : (s % base) - 10 + 'a';
		s = s / base;
	}
	return (str);
}

static char	*ft_convert(long long int n, int base, char *str, int i)
{
	long long int	d;
	char			temp;

	d = 1;
	if (n < 0)
	{
		n = -n;
		str[i] = '-';
		i++;
	}
	while (n / d >= base)
		d *= base;
	while (d > 0)
	{
		temp = '0' + n / d;
		if (temp > '9')
			str[i] = (temp + 39);
		else
			str[i] = temp;
		n %= d;
		d /= base;
		i++;
	}
	return (str);
}

char		*ft_itoa_base(long long int n, int base)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(*str) * 21);
	i = 0;
	while (i < 21)
	{
		str[i] = '\0';
		i++;
	}
	i = 0;
	if (base == 16)
		return (ft_convert((unsigned int)n, base, str, i));
	else if (base == 8)
		return (ft_convert((unsigned long long int)n, base, str, i));
	else
		return (ft_convert(n, base, str, i));
}
