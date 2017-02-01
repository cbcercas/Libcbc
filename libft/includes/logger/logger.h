/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 20:37:10 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/01 17:40:32 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_H
# define LOGGER_H

enum e_d_lvl
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
void	logger_log(enum e_d_lvl lvl, const char *fmt, ...);
int		logger_close();

#define log_fatal(...) logger_log(D_FATAL, __VA_ARGS__)
#define log_error(...) logger_log(D_ERROR, __VA_ARGS__)
#define log_warn(...) logger_log(D_WARN, __VA_ARGS__)
#define log_info(...) logger_log(D_INFO, __VA_ARGS__)
#define log_dbg1(...) logger_log(D_DEBUG1, __VA_ARGS__)
#define log_dbg2(...) logger_log(D_DEBUG2, __VA_ARGS__)
#define log_dbg3(...) logger_log(D_DEBUG3, __VA_ARGS__)


#endif