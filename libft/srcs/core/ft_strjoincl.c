/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoincl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 11:45:28 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/17 16:27:56 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoincl(char *s1, char *s2, int free)
{
	char	*s;
	size_t	ls1;
	size_t	ls2;

	ls1 = (s1) ? ft_strlen(s1) : 0;
	ls2 = (s2) ? ft_strlen(s2) : 0;
	if (s1 || s2)
	{
		s = ft_strnew(ls1 + ls2 + 1);
		if (s)
		{
			if (s1)
				s = ft_strcpy(s, s1);
			if (s2)
				ft_strlcat(s, s2, ls1 + ls2 + 1);
		}
		else
			s = NULL;
	}
	else
		s = NULL;
	((free == 1 || free == 3) && s1) ? ft_strdel(&s1) : 0;
	((free == 2 || free == 3) && s2) ? ft_strdel(&s2) : 0;
	return (s);
}
