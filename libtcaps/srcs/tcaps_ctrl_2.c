/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_ctrl_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 12:43:21 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/19 05:56:39 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtcaps.h>

BOOL	is_ctrl_l(const char *buff)
{
	if (ft_strequ(buff, KEY_CODE_CTRL_L))
		return (true);
	return (false);
}

BOOL	is_ctrl_j(const char *buff)
{
	if (ft_strequ(buff, KEY_CODE_ENTER))
		return (true);
	return (false);
}

BOOL	is_ctrl_r(const char *buff)
{
	if (ft_strequ(buff, KEY_CODE_CTRL_R))
		return (true);
	return (false);
}

BOOL	is_ctrl_v(const char *buff)
{
	if (ft_strequ(buff, KEY_CODE_CTRL_V))
		return (true);
	return (false);
}

BOOL	is_ctrl_w(const char *buff)
{
	if (ft_strequ(buff, KEY_CODE_CTRL_W))
		return (true);
	return (false);
}
