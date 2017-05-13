/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 15:42:12 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/13 16:36:12 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# define BUFF_SIZE 5000
# define RETURN_LEN 0

# if RETURN_LEN == 1
#  define RETURN_TYPE size_t
# else
#  define RETURN_TYPE int
# endif

typedef struct	s_fd
{
	int			fd;
	char		*rest;
	struct s_fd *next;
}				t_fd;

RETURN_TYPE		gnp(int const fd, char **line, char c, size_t b_size);
RETURN_TYPE		get_next_line(int const fd, char **line);

#endif
