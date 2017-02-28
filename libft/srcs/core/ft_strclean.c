/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 03:53:42 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/28 03:59:31 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

char	*ft_strclean(char *str)
{
	char *tmp;
	char *tmp_save;

	if (!str || !(tmp = ft_strnew(ft_strlen(str))))
		return (NULL);
	tmp_save = tmp;
	while (*str)
	{
		while (*str && ft_iswhitespace(*str))
			str++;
		while (*str && !ft_iswhitespace(*str))
		{
			*tmp = *str;
			str++;
			tmp++;
		}
		if (*str && ft_iswhitespace(*str))
		{
			*tmp = ' ';
			tmp++;
		}
	}
	tmp = ft_strdup(tmp_save);
	ft_strdel(&tmp_save);
	return(tmp);
}
