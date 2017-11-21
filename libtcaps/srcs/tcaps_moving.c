/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_moving.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 05:58:44 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/19 05:58:58 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtcaps.h>

void	move_cursor_left(t_cpos *cpos, struct winsize *ts)
{
	log_dbg3("Move cursor left");
	if (cpos->cp_col == 0)
	{
		tputs(tgetstr("up", NULL), 0, &ft_putc_in);
		while (cpos->cp_col + 1 < ts->ws_col)
		{
			tputs(tgetstr("nd", NULL), 0, &ft_putc_in);
			cpos->cp_col += 1;
		}
		cpos->cp_line -= 1;
	}
	else
	{
		tputs(tgetstr("le", NULL), 0, &ft_putc_in);
		cpos->cp_col -= 1;
	}
}

void	move_cursor_right(t_cpos *cpos, struct winsize *ts)
{
	log_dbg3("Move cursor right");
	if (cpos->cp_col + 1 == ts->ws_col)
	{
		tputs(tgetstr("do", NULL), 0, &ft_putc_in);
		tputs(tgetstr("cr", NULL), 0, &ft_putc_in);
		cpos->cp_col = 0;
		cpos->cp_line += 1;
	}
	else
	{
		tputs(tgetstr("nd", NULL), 0, &ft_putc_in);
		cpos->cp_col += 1;
	}
}

void	move_cursor_down(t_cpos *cpos)
{
	log_dbg3("Move cursor down");
	tputs(tgetstr("do", NULL), 0, &ft_putc_in);
	cpos->cp_line += 1;

}

void	move_cursor_up(t_cpos *cpos)
{
	log_dbg3("Move cursor down");
	tputs(tgetstr("up", NULL), 0, &ft_putc_in);
	cpos->cp_line -= 1;

}

void	move_cursor_to_col(t_cpos *cpos, struct winsize *ts, unsigned short col)
{
	if (!cpos || !ts || (cpos->cp_col == col))
		return;
	while (cpos->cp_col < col)
		move_cursor_right(cpos, ts);
	while (cpos->cp_col > col)
		move_cursor_left(cpos, ts);
}
