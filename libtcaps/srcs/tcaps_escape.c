/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_esc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 14:56:30 by chbravo-          #+#    #+#             */
/*   Updated: 2017/11/04 14:56:30 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtcaps.h>

BOOL	is_escape(const char *buff)
{
	if (ft_strequ(buff, KEY_CODE_ESC))
		return (true);
	return (false);
}