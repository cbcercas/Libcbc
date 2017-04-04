/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_ctrl_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 12:43:21 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/30 14:32:44 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtcaps.h>

BOOL	is_ctrl_l(const char *buff)
{
	if (ft_strequ(buff, KEY_CODE_CTRL_L))
		return (true);
	return (false);
}
