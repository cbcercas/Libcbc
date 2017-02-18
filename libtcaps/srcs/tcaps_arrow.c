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
	static char	*arrow = NULL;

	if (arrow == NULL)
	{
		arrow = tgetstr(KEY_CODE_RARROW, NULL);
		arrow[1] = 91;
	}
	if (ft_strequ(buff, arrow))
		return (true);
	return (false);
}

BOOL	is_left_arrow(const char *buff)
{
	static char	*arrow = NULL;

	if (arrow == NULL)
	{
		arrow = tgetstr(KEY_CODE_LARROW, NULL);
		arrow[1] = 91;
	}
	if (ft_strequ(buff, arrow))
		return (true);
	return (false);
}

BOOL	is_down_arrow(const char *buff)
{
	static char	*arrow = NULL;

	if (arrow == NULL)
	{
		arrow = tgetstr(KEY_CODE_DARROW, NULL);
		arrow[1] = 91;
	}
	if (ft_strequ(buff, arrow))
		return (true);
	return (false);
}

BOOL	is_up_arrow(const char *buff)
{
	static char	*arrow = NULL;

	if (arrow == NULL)
	{
		arrow = tgetstr(KEY_CODE_UARROW, NULL);
		arrow[1] = 91;
	}
	if (ft_strequ(buff, arrow))
		return (true);
	return (false);
}