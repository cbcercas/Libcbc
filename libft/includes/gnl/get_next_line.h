/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 15:42:12 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/15 14:28:48 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/includes/libft.h"
# define BUFF_SIZE 5000
# define RETURN_LEN 0

# if RETURN_LEN == 1
# define RETURN_TYPE size_t
# else
# define RETURN_TYPE int
# endif
typedef struct	s_fd
{
	int			fd;
	char		*rest;
	struct s_fd *next;
}				t_fd;

int				get_next_line(int const fd, char **line);

#endif