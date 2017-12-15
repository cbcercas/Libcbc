/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:02:51 by chbravo-          #+#    #+#             */
/*   Updated: 2015/12/09 12:59:24 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char *dest;
	unsigned char *src;
	unsigned char c2;

	c2 = (unsigned char)c;
	dest = (unsigned char *)s1;
	src = (unsigned char *)s2;
	while (n)
	{
		*dest = *src;
		dest++;
		if (*src == c2)
			return (dest);
		src++;
		n--;
	}
	return (NULL);
}
