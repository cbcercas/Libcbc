/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 12:57:56 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/19 05:59:46 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtcaps.h>

BOOL	is_delete(const char *buff)
{
	static char	*delete;

	delete = NULL;
	if (delete == NULL)
	{
		if ((delete = tgetstr(KEY_CODE_DELETE, NULL)) == NULL)
		{
			log_fatal("Lib_tcaps: failed to get delete code.");
			return (false);
		}
	}
	if (ft_strequ(buff, delete))
		return (true);
	return (false);
}
