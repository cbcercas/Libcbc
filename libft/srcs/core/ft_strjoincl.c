/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoincl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 11:45:28 by chbravo-          #+#    #+#             */
/*   Updated: 2016/11/18 11:45:54 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoincl(char *s1, char *s2, int free)
{
	char	*s;

	if (s1 || s2)
	{
		s = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (s)
		{
			s = ft_strcpy(s, s1);
			ft_strlcat(s, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
		}
		else
			s = NULL;
	}
	else
		s = NULL;
	if (free == 1 || free == 3)
		ft_strdel((char **)&s1);
	if (free == 2 || free == 3)
		ft_strdel((char **)&s2);
	return (s);
}
