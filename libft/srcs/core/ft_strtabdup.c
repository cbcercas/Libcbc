/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 22:07:29 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/15 22:08:06 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	**ft_strtabdup(char **tab)
{
	int		i;
	char	**tabcpy;

	tabcpy = ft_memalloc(ft_tablen(tab));
	i = 0;
	while (tab[i])
	{
		tabcpy[i] = ft_strdup(tab[i]);
		if (!tabcpy[i])
		{
			ft_freetab(tabcpy, i);
			return (NULL);
		}
		i++;
	}
	tabcpy[i] = NULL;
	return (tabcpy);
}