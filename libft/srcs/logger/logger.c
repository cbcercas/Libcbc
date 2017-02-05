/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 20:26:23 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/01 18:14:07 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#define LOGGER_MAIN
#include <logger/logger_intern.h>
#undef LOGGER_MAIN

int				g_logger_fd;
enum e_d_lvl	g_logger_lvl;
char			*g_logger_pname;
char			*g_logger_file;

/**
** @brief      Initialise the logger
**             create file if missing
**             clear the file if size > 512Ko
**
** @param[in]  lvl       The log level
** @param[in]  pname     The programme name
** @param[in]  filename  The filename
**
** @return     -1 on error or no log, the log fd otherwise
*/
int	logger_init(enum e_d_lvl lvl, const char *pname, const char *filename)
{
	char *log_start;

	g_logger_fd = -1;
	if (lvl == D_OFF || !filename || !pname || lvl >= D_MAX)
		return (g_logger_fd);
	g_logger_file = ft_strdup(filename);
	g_logger_fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0644);
	g_logger_lvl = lvl;
	g_logger_pname = ft_strdup(pname);
	logger_clear(false);
	log_start = ft_strjoin("new intance of ", g_logger_pname);
	ft_dprintf(g_logger_fd, "##########################################\n");
	ft_dprintf(g_logger_fd, " %30s\n", log_start);
	ft_dprintf(g_logger_fd, "##########################################\n");
	ft_strdel(&log_start);
	return (g_logger_fd);
}

int	logger_close()
{
	char *log_start;
	int ret;

	log_start = ft_strjoin("end of intance ", g_logger_pname);
	ft_dprintf(g_logger_fd, "##########################################\n");
	ft_dprintf(g_logger_fd, " %30s\n", log_start);
	ft_dprintf(g_logger_fd, "##########################################\n");
	ft_strdel(&log_start);
	if ((ret = close(g_logger_fd)) == 0)
		g_logger_fd = -1;
	ft_strdel(&g_logger_file);
	ft_strdel(&g_logger_pname);
	return (ret);
}

void	logger_log(enum e_d_lvl lvl, const char *format, ...)
{
	va_list		list;
	time_t		now;
	struct tm	*now_tm;

	if (!is_valid_fd() || g_logger_fd == -1
		|| lvl == D_OFF || lvl >= D_MAX || lvl > g_logger_lvl)
		return;
	now = time(0);
	now_tm = gmtime(&now);
	va_start(list, format);
	ft_dprintf(g_logger_fd, get_log_format(lvl), \
		1900 + now_tm->tm_year, 1 + now_tm->tm_mon, now_tm->tm_mday, \
		now_tm->tm_hour, now_tm->tm_min, now_tm->tm_sec, g_logger_pname);
	ft_vdprintf(g_logger_fd, format, list);
	ft_putchar_fd('\n', g_logger_fd);
	va_end(list);
}
