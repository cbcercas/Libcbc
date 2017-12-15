/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_escape_enter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 13:50:13 by jlasne            #+#    #+#             */
/*   Updated: 2017/12/12 13:50:14 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtcaps.h>

BOOL	is_escape_enter(const char *buff)
{
	if (ft_strequ(buff, KEY_CODE_ESC_ENTER))
		return (true);
	return (false);
}
