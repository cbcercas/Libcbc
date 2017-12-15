/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:02:51 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/13 20:16:07 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *src)
{
	char	*dup;
	size_t	size;

	size = ft_strlen(src);
	if ((dup = ft_strnew(size)))
	{
		ft_memcpy(dup, src, size);
		return (dup);
	}
	return (NULL);
}

char	*ft_strdup_free(char *src, int free)
{
	char	*dup;
	size_t	size;

	size = ft_strlen(src);
	if ((dup = ft_strnew(size)))
	{
		ft_memcpy(dup, src, size);
		if (free)
			ft_strdel(&src);
		return (dup);
	}
	return (NULL);
}

char	*ft_strndup_free(char *src, size_t start, size_t size, int free)
{
	char	*dup;

	if ((dup = ft_strnew(size)))
	{
		ft_memcpy(dup, src + start, size);
		if (free)
			ft_strdel(&src);
		return (dup);
	}
	return (NULL);
}
