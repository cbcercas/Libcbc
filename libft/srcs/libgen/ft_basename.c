/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:30:44 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/30 13:36:58 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

const char	*ft_basename(char *path)
{
	static char	*str = NULL;
	char		*tmp;

	if (str)
		ft_strdel(&str);
	if (!path)
		return (NULL);
	if (ft_strequ(path, "/") || ft_strequ(path, ".") || ft_strequ(path, "..")
		|| ft_strrchr(path, '/') == 0)
		return (path);
	tmp = ft_strdup(path);
	if (tmp[ft_strlen(tmp) - 1] == '/')
		tmp[ft_strlen(tmp) - 1] = '\0';
	if (!(str = ft_strrchr(tmp, '/')))
		str = ft_strdup(tmp);
	else
		str = ft_strdup(str + 1);
	ft_strdel(&tmp);
	return (str);
}
