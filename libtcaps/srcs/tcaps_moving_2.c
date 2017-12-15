/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_moving.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 05:58:44 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/19 05:58:58 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtcaps.h>

void	move_cursor_to(t_cpos *dest, t_cpos *ori, struct winsize *ts)
{
	if (!dest || !ori || dest->cp_col > ts->ws_col)
		return ;
	tputs(tgetstr("cr", NULL), 1, &ft_putc_in);
	ori->cp_col = 0;
	while (ori->cp_line < dest->cp_line)
	{
		tputs(tgetstr("do", NULL), 0, &ft_putc_in);
		ori->cp_line += 1;
	}
	while (ori->cp_line > dest->cp_line)
	{
		tputs(tgetstr("up", NULL), 0, &ft_putc_in);
		ori->cp_line -= 1;
	}
	while (ori->cp_col < dest->cp_col)
	{
		tputs(tgetstr("nd", NULL), 0, &ft_putc_in);
		ori->cp_col += 1;
	}
}
