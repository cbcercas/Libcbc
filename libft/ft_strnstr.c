/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:02:51 by chbravo-          #+#    #+#             */
/*   Updated: 2015/12/09 12:05:12 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, size_t n)
{
	int		j;
	char	*ret;

	if (*to_find == '\0')
		return (str);
	while (*str != '\0' && n > 0)
	{
		j = 0;
		ret = str;
		while ((to_find[j] == str[j]) && (to_find[j] != '\0') && ((j - n) > 0))
			j++;
		if (to_find[j] == '\0')
			return (ret);
		str++;
		n--;
	}
	return (NULL);
}
