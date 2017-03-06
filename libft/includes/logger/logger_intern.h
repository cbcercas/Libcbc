/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger_intern.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 20:37:10 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/01 17:46:01 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_INTERN_H
# define LOGGER_INTERN_H

# include <fcntl.h>
# include <stdarg.h>
# include <time.h>
# include <sys/stat.h>
# include <libft.h>
# include <logger/logger.h>
# include <ft_printf/libftprintf.h>

# ifndef LOGGER_MAIN
extern int	g_logger_fd;
extern enum	e_d_lvl	g_logger_lvl;
extern char	*g_logger_pname;
extern char	*g_logger_file;
# endif

# ifndef F_GETPATH
#  define F_GETPATH	50
# endif

char	*get_log_format(enum e_d_lvl lvl);
BOOL	is_valid_fd(void);
void	logger_clear(BOOL force);

#endif

