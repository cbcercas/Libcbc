/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_home_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 12:43:21 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/19 05:58:03 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtcaps.h>

BOOL	is_home(const char *buff)
{
	if (ft_strequ(buff, KEY_CODE_HOME))
		return (true);
	return (false);
}

BOOL	is_end(const char *buff)
{
	if (ft_strequ(buff, KEY_CODE_END))
		return (true);
	return (false);
}
