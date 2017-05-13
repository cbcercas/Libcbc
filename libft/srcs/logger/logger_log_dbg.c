/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger_log_dbg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 16:38:11 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/13 21:26:28 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LOGGER_MAIN
#include <logger/logger_intern.h>
#undef LOGGER_MAIN

void	log_dbg1(const char *fmt, ...)
{
	va_list		list;

	va_start(list, fmt);
	logger_log(D_DEBUG1, fmt, list);
	va_end(list);
}

void	log_dbg2(const char *fmt, ...)
{
	va_list		list;

	va_start(list, fmt);
	logger_log(D_DEBUG2, fmt, list);
	va_end(list);
}

void	log_dbg3(const char *fmt, ...)
{
	va_list		list;

	va_start(list, fmt);
	logger_log(D_DEBUG3, fmt, list);
	va_end(list);
}
