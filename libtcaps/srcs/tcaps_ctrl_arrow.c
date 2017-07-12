/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_ctrl_arrow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 21:44:30 by chbravo-          #+#    #+#             */
/*   Updated: 2017/03/30 14:33:16 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtcaps.h>

BOOL	is_ctrl_right_arrow(const char *buff)
{
	if (ft_strequ(buff, KEY_CODE_CTRL_RARROW))
		return (true);
	return (false);
}

BOOL	is_ctrl_left_arrow(const char *buff)
{
	if (ft_strequ(buff, KEY_CODE_CTRL_LARROW))
		return (true);
	return (false);
}

BOOL	is_ctrl_up_arrow(const char *buff)
{
	if (ft_strequ(buff, KEY_CODE_CTRL_UARROW))
		return (true);
	return (false);
}

BOOL	is_ctrl_down_arrow(const char *buff)
{
	if (ft_strequ(buff, KEY_CODE_CTRL_DARROW))
		return (true);
	return (false);
}
