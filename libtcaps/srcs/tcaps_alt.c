/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_alt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 21:44:30 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/19 05:54:03 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtcaps.h>

BOOL	is_alt_c(const char *buff)
{
	if (ft_strequ(buff, KEY_CODE_ALT_C))
		return (true);
	return (false);
}

BOOL	is_alt_i(const char *buff)
{
	if (ft_strequ(buff, KEY_CODE_ALT_I))
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

BOOL	is_alt_s(const char *buff)
{
	if (ft_strequ(buff, KEY_CODE_ALT_S))
		return (true);
	return (false);
}
