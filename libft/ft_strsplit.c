/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:02:51 by chbravo-          #+#    #+#             */
/*   Updated: 2015/12/09 12:01:27 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	nb[3];

	if (!s || !c)
		return (NULL);
	nb[0] = ft_nbword(s--, c);
	nb[1] = 0;
	tab = (char **)malloc(sizeof(*tab) * (nb[0] + 1));
	if (tab)
	{
		while (*++s != '\0')
			if (*s != c && *s != '\0')
			{
				nb[2] = ft_wordlen(s, c);
				tab[nb[1]] = ft_strsub((char *)s, 0, nb[2]);
				if (!tab[nb[1]++])
				{
					ft_freetab(tab, nb[0]);
					return (NULL);
				}
				s += nb[2] - 1;
			}
		tab[nb[1]] = NULL;
	}
	return (tab);
}
