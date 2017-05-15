/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger_log.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 16:38:11 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/15 02:24:16 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <intern/logger_intern.h>

void	log_fatal(const char *fmt, ...)
{
	va_list		list;

	va_start(list, fmt);
	logger_log(D_FATAL, fmt, list);
	va_end(list);
}

void	log_error(const char *fmt, ...)
{
	va_list		list;

	va_start(list, fmt);
	logger_log(D_ERROR, fmt, list);
	va_end(list);
}

void	log_warn(const char *fmt, ...)
{
	va_list		list;

	va_start(list, fmt);
	logger_log(D_WARN, fmt, list);
	va_end(list);
}

void	log_info(const char *fmt, ...)
{
	va_list		list;

	va_start(list, fmt);
	logger_log(D_INFO, fmt, list);
	va_end(list);
}
