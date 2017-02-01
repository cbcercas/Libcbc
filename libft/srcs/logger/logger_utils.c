/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 17:34:40 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/01 17:43:15 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <logger/logger_intern.h>


char *get_log_format(enum e_d_lvl lvl)
{
	char *str;

	str = NULL;
	if (lvl == D_FATAL)
		str = "\033[31m[%4d-%02d-%02d %02d:%02d:%02d] %s: Fatal:\033[0m ";
	else if (lvl == D_ERROR)
		str = "\033[33m[%4d-%02d-%02d %02d:%02d:%02d] %s: Error:\033[0m ";
	else if (lvl == D_WARN)
		str = "\033[34m[%4d-%02d-%02d %02d:%02d:%02d] %s: Warning:\033[0m ";
	else if (lvl == D_INFO)
		str = "[%4d-%02d-%02d %02d:%02d:%02d] %s: Info: ";
	else if (lvl == D_DEBUG1)
		str = "\033[32m[%4d-%02d-%02d %02d:%02d:%02d] %s: Debug lv1:\033[0m ";
	else if (lvl == D_DEBUG2)
		str = "\033[35m[%4d-%02d-%02d %02d:%02d:%02d] %s: Debug lv2:\033[0m ";
	else if (lvl == D_DEBUG3)
		str = "\033[36m[%4d-%02d-%02d %02d:%02d:%02d] %s: Debug lv3:\033[0m ";
	return (str);
}

BOOL	is_valid_fd(void)
{
	char buf[PATH_MAX];

	if (g_logger_fd == -1)
		return (false);
	if (fcntl(g_logger_fd, F_GETFD))
	{
		fcntl(g_logger_fd, F_GETPATH, buf);
		if (access(buf, F_OK | W_OK))
			logger_init(g_logger_lvl, g_logger_pname, g_logger_file);
	}
	return (true);
}

void		logger_clear(BOOL force)
{
	struct stat st;

	if (stat(g_logger_file, &st) == 0)
		if (st.st_size >= 524288 || force)
			unlink(g_logger_file);
}