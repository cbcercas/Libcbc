/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 12:57:56 by chbravo-          #+#    #+#             */
/*   Updated: 2017/03/30 13:42:12 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtcaps.h>

BOOL	is_delete(const char *buff)
{
	static char     *delete = NULL;
	if (delete == NULL)
	{
		if((delete = tgetstr(KEY_CODE_DELETE, NULL)) == NULL)
		{
			log_fatal("Lib_tcaps: failed to get delete code.");
			ft_dprintf(STDERR_FILENO, "Lib_tcaps: failed to get delete code.");
		}
	}
	if (ft_strequ(buff, delete))
		return (true);
	return (false);
}
