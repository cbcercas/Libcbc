#include <libtcaps.h>

void	move_cursor_left(t_cpos *cpos, struct winsize *ts)
{
	log_dbg3("Move cursor left");
	if (cpos->cp_col == 0)
	{
		tputs(tgetstr("up", NULL), 0, &ft_putchar2);
		while(cpos->cp_col + 1 < ts->ws_col)
		{
			tputs(tgetstr("nd", NULL), 0, &ft_putchar2);
			cpos->cp_col += 1;
		}
		cpos->cp_line -= 1;
	}
	else
	{
		tputs(tgetstr("le", NULL), 0, &ft_putchar2);
		cpos->cp_col -= 1;
	}
}

void	move_cursor_right(t_cpos *cpos, struct winsize *ts)
{
	log_dbg3("Move cursor right");
	if (cpos->cp_col + 1 == ts->ws_col)
	{
		tputs(tgetstr("do", NULL), 0, &ft_putchar2);
		tputs(tgetstr("cr", NULL), 0, &ft_putchar2);
		cpos->cp_col = 0;
		cpos->cp_line += 1;
	}
	else
	{
		tputs(tgetstr("nd", NULL), 0, &ft_putchar2);
		cpos->cp_col += 1;
	}
}