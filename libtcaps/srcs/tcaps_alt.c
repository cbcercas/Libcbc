/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_alt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 21:44:30 by chbravo-          #+#    #+#             */
/*   Updated: 2017/03/30 14:33:16 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtcaps.h>

BOOL	is_alt_c(const char *buff)
{
	if (ft_strequ(buff, KEY_CODE_ALT_C))
		return (true);
	return (false);
}

BOOL	is_alt_v(const char *buff)
{
	if (ft_strequ(buff, KEY_CODE_ALT_V))
		return (true);
	return (false);
}

BOOL	is_alt_x(const char *buff)
{
	if (ft_strequ(buff, KEY_CODE_ALT_X))
		return (true);
	return (false);
}