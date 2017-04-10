/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:50:35 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/31 18:45:19 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gnl/get_next_line.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>


static t_fd	*ft_fd_add(int fd)
{
	t_fd	*elem;

	if (!(elem = ft_memalloc(sizeof(t_fd))))
		return (NULL);
	elem->fd = fd;
	elem->rest = NULL;
	elem->next = NULL;
	return (elem);
}

int			ft_in_rest(t_fd *elem, char **line, const char c)
{
	char *tmp;

	tmp = NULL;
	if (elem->rest && ft_strchr(elem->rest, c))
	{
		*line = ft_strsub(elem->rest, 0, ft_strchr(elem->rest, c) - elem->rest);
		if ((ft_strlen(*line) + 1) != ft_strlen(elem->rest))
			tmp = ft_strdup(ft_strchr(elem->rest, c) + 1);
		ft_strdel(&elem->rest);
		elem->rest = tmp;
		return (1);
	}
	else
		return (0);
}


RETURN_TYPE	ft_next_line(t_fd *elem, char **line, const char c, size_t b_size)
{
	char	buf[b_size + 1];
	ssize_t	ret;

	ret = 1;
	ft_bzero(buf, b_size + 1);
	while(ret > 0 && !*line)
		if (ft_in_rest(elem, line, c))
			ret = 0;
		else
		{
			ret = read(elem->fd, buf, b_size);
			buf[ret] = '\0';
			if (ret > 0)
				elem->rest = ft_strjoincl(elem->rest, buf, 1);
			else if (ret == 0)
			{
				*line = elem->rest;
				elem->rest = NULL;
				break;
			}
			else if (ret == -1)
				return (-1);
		}
	ret = ((RETURN_LEN && *line) ? ft_strlen(*line) : 1);
	return ((*line) ? (RETURN_TYPE)ret : (RETURN_TYPE)0);
}

RETURN_TYPE	gnp(int const fd, char **line, const char c, size_t b_size)
{
	static t_fd	*fd_list = NULL;
	t_fd		*elem;

	if (fd < 0 || !line)
		return (-1);
	*line = NULL;
	if (!fd_list && !(fd_list = ft_fd_add(fd)))
		return -1;
	elem = fd_list;
	while(elem && elem->fd != fd)
	{
		if (!elem->next && !(elem->next = ft_fd_add(fd)))
			return (-1);
		elem = elem->next;
	}
	return (ft_next_line(elem, line, c, b_size));
}