/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:02:51 by chbravo-          #+#    #+#             */
/*   Updated: 2015/12/09 14:42:58 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char ch;
	char *s2;

	ch = (char)c;
	s2 = (char *)s;
	while (*s2 != '\0')
		s2++;
	while (*s2 != ch)
	{
		if (s2 == s)
			return (0);
		s2--;
	}
	return ((char *)s2);
}
