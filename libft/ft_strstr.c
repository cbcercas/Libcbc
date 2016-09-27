/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:02:51 by chbravo-          #+#    #+#             */
/*   Updated: 2015/12/10 17:36:53 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	int		j;

	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		j = 0;
		while (to_find[j] == str[j] && to_find[j] != '\0')
			j++;
		if (to_find[j] == '\0')
			return (str);
		str++;
	}
	return (0);
}
