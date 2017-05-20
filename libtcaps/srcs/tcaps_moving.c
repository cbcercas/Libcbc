#include <libtcaps.h>

void	move_cursor_left(t_cpos *cpos, t_ts *ts)
{
	log_dbg3("Move cursor left");
	if (cpos->cp_col <= 1)
		tputs(tgoto(tgetstr("cm", NULL), ts->ts_cols, cpos->cp_line - 2), 1, &ft_putchar2);
	else
		tputs(tgetstr("le", NULL), 0, &ft_putchar2);
	*cpos = get_cursor_pos();
}

void	move_cursor_right(t_cpos *cpos, t_ts *ts)
{
	log_dbg3("Move cursor left");
	if (cpos->cp_col == ts->ts_cols)
		tputs(tgoto(tgetstr("cm", NULL), 1, cpos->cp_line + 1), 1, &ft_putchar2);
	else
		tputs(tgetstr("nd", NULL), 0, &ft_putchar2);
	*cpos = get_cursor_pos();
}