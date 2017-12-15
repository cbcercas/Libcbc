/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 13:50:30 by jlasne            #+#    #+#             */
/*   Updated: 2017/12/12 13:50:33 by jlasne           ###   ########.fr       */
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
