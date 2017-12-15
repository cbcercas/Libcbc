/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 12:57:56 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/19 05:59:30 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtcaps.h>

BOOL	is_tab(const char *buff)
{
	if (ft_strequ(buff, KEY_CODE_TAB))
		return (true);
	return (false);
}