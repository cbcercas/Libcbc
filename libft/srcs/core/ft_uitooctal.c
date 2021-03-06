/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitooctal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 02:58:36 by chbravo-          #+#    #+#             */
/*   Updated: 2016/11/18 11:42:46 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitooctal(uintmax_t nb, int prefix)
{
	char	*nbbase;
	char	*ret;
	int		i;

	nbbase = ft_uitobase(nb, 8);
	if (!prefix)
		return (nbbase);
	ret = ft_strnew(prefix + ft_strlen(nbbase));
	ret[0] = '0';
	i = 0;
	while (nbbase[i] != '\0')
	{
		ret[i + 1] = nbbase[i];
		i++;
	}
	free(nbbase);
	return (ret);
}
