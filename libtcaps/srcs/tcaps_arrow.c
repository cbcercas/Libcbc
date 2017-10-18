/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_arrow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 21:41:48 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/17 23:51:08 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libtcaps.h>

BOOL	is_right_arrow(const char *buff)
{
	static char     *arrow = NULL;

	if (arrow == NULL)
	{
		if((arrow = tgetstr(KEY_CODE_RARROW, NULL)) == NULL)
		{
			log_fatal("Lib_tcaps: failed to get right arrow code.");
			ft_dprintf(STDERR_FILENO, "Lib_tcaps: failed to get right arrow code.");
		}
		else
			arrow[1] = 91;
	}
	if (ft_strequ(buff, arrow))
		return (true);
	return (false);
}

BOOL	is_left_arrow(const char *buff)
{
	static char     *arrow = NULL;

	if (arrow == NULL)
	{
		if ((arrow = tgetstr(KEY_CODE_LARROW, NULL)) == NULL)
		{
			log_fatal("Lib_tcaps: failed to get arrow code.");
			ft_dprintf(STDERR_FILENO, "Lib_tcaps: failed to get arrow code.");
		}
		else
			arrow[1] = 91;
	}
	if (ft_strequ(buff, arrow))
		return (true);
	return (false);
}

BOOL	is_down_arrow(const char *buff)
{
	static char     *arrow = NULL;

	if (arrow == NULL)
	{
		if ((arrow = tgetstr(KEY_CODE_DARROW, NULL)) == NULL)
		{
			log_fatal("Lib_tcaps: failed to get arrow code.");
			ft_dprintf(STDERR_FILENO, "Lib_tcaps: failed to get arrow code.");
		}
		else
			arrow[1] = 91;
	}
	if (ft_strequ(buff, arrow))
		return (true);
	return (false);
}

BOOL	is_up_arrow(const char *buff)
{
	static char     *arrow = NULL;

	if (arrow == NULL)
	{
		if ((arrow = tgetstr(KEY_CODE_UARROW, NULL)) == NULL)
		{
			log_fatal("Lib_tcaps: failed to get arrow code.");
			ft_dprintf(STDERR_FILENO, "Lib_tcaps: failed to get arrow code.");
		}
		else
			arrow[1] = 91;
	}
	if (ft_strequ(buff, arrow))
		return (true);
	return (false);
}
