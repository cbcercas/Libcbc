/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 20:37:10 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/17 19:23:49 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_H
# define LOGGER_H
# include "stdarg.h"

enum	e_d_lvl
{
	D_OFF,
	D_FATAL,
	D_ERROR,
	D_WARN,
	D_INFO,
	D_DEBUG1,
	D_DEBUG2,
	D_DEBUG3,
	D_MAX
};

int		logger_init(enum e_d_lvl lvl, const char *pname, const char *filename);
void	logger_log(enum e_d_lvl lvl, const char *fmt, va_list list);
int		logger_close();

void	log_fatal(const char *fmt, ...);
void	log_error(const char *fmt, ...);
void	log_warn(const char *fmt, ...);
void	log_info(const char *fmt, ...);
void	log_dbg1(const char *fmt, ...);
void	log_dbg2(const char *fmt, ...);
void	log_dbg3(const char *fmt, ...);

#endif
