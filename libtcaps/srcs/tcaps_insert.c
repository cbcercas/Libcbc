/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 12:57:56 by chbravo-            #+#    #+#             */
/*   Updated: 2017/10/19 05:59:55 by chbravo-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtcaps.h>

BOOL	is_insert(const char *buff)
{
	static char	*insert = NULL;

	if (insert == NULL)
	{
		if ((insert = tgetstr(KEY_CODE_INSERT, NULL)) == NULL)
		{
			log_fatal("Lib_tcaps: failed to get insert code.");
			ft_dprintf(STDERR_FILENO, "Lib_tcaps: failed to get insert code.");
		}
	}
	if (ft_strequ(buff, insert))
	{
		return (true);
	}
	return (false);
}
