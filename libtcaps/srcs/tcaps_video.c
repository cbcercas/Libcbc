/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_video.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:58:43 by chbravo-          #+#    #+#             */
/*   Updated: 2017/11/10 16:58:43 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtcaps.h>

void	tcaps_video_reverse(void)
{
	tputs(tgetstr("mr", NULL), 0, &ft_putchar2);
}

void	tcaps_video_default(void)
{
	tputs(tgetstr("me", NULL), 0, &ft_putchar2);
}

void	tcaps_video_underline(BOOL on)
{
	if (on)
		tputs(tgetstr("us", NULL), 0, &ft_putchar2);
	else
		tputs(tgetstr("ue", NULL), 0, &ft_putchar2);
}
