/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 14:37:43 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/18 12:38:53 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <tcaps_test.h>

int main(int ac, char const *av[])
{
	(void)ac;
	(void)av;
	char	buff[MAX_KEY_STRING_LEN];
	BOOL	stop;
	int		res;
	t_key	key;
	int		i = 0;
	t_ts	ts;
	t_cpos	cpos;

	raw_terminal_mode();
	ts = get_term_size();
	cpos = get_cursor_pos();
	log_info("Terminal size: %lux%lu", ts.ts_cols, ts.ts_lines);
	log_info("Cursor position: %dx%d", cpos.cp_col, cpos.cp_line);
	logger_init(D_MAX - 1, PROGNAME, "test.log");
	stop = false;
	while (stop == false)
	{
		raw_terminal_mode();
		(void)ft_bzero((void *)buff, MAX_KEY_STRING_LEN);
		res = read(STDIN_FILENO, buff, MAX_KEY_STRING_LEN);
		buff[res] = '\0';
		key = key_get(buff);
		if (ft_strcmp(key.key_code, KEY_CODE_NONE))
			stop = key_exec(&key);
		else
			if (ft_isprint(key.key[0]))
				ft_printf("%c", key.key[0]);
		key_del(&key);
		if (stop == false && i++ == 10)
			stop = true;
		default_terminal_mode();
	}
	tputs(tgetstr("cl", NULL), 0, &ft_putchar2);
	default_terminal_mode();
	logger_close();
	return 0;
}