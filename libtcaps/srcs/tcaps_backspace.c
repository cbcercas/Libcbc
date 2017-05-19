/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_backspace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 12:57:56 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/30 13:42:12 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtcaps.h>

BOOL	is_backspace(const char *buff)
{
	static char     *backspace = NULL;

	if (backspace == NULL)
	{
		if((backspace = tgetstr(KEY_CODE_BACKSPACE, NULL)) == NULL)
		{
			log_fatal("Lib_tcaps: failed to get backspace code.");
			ft_dprintf(STDERR_FILENO,
					   "Lib_tcaps: failed to get backspace code.");
		}
	}
	if (ft_strequ(buff, backspace))
	{
		return (true);
	}
	return (false);
}
