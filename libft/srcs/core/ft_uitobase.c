/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitobase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 02:58:36 by chbravo-          #+#    #+#             */
/*   Updated: 2016/11/18 11:44:12 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitobase(uintmax_t nb, unsigned int base)
{
	char		*ret;
	uintmax_t	rst;
	int			i;

	ret = ft_strnew(65);
	i = 0;
	if (nb == 0)
		ret[i] = '0';
	while (nb > 0)
	{
		rst = nb % base;
		nb /= base;
		ret[i] = rst + '0';
		i++;
	}
	ft_strrev(ret);
	return (ret);
}
