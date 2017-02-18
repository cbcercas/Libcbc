/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_ctrl_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 14:41:47 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/17 23:50:48 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libtcaps.h>

BOOL	is_ctrl_c(const char *buff)
{
	if (ft_strequ(buff, KEY_CODE_CTRL_C))
		return (true);
	return (false);
}

BOOL	is_ctrl_d(const char *buff)
{
	if (ft_strequ(buff, KEY_CODE_CTRL_D))
		return (true);
	return (false);
}