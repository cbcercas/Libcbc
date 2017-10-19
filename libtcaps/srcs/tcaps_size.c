/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 14:41:47 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/19 06:00:26 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtcaps.h>

t_ts	get_term_size(void)
{
	t_ts			tws;
	int				tmp;

	ft_bzero(&tws, sizeof(tws));
	tmp = tgetnum("co");
	if (tmp < 1)
		log_fatal("Libtcaps: Failed to read terminal size!");
	else
	{
		tws.ts_cols = (unsigned short)tmp;
		tmp = tgetnum("li");
		if (tmp < 1)
			log_fatal("Libtcaps: Failed to read terminal size!");
		else
		{
			tws.ts_lines = (unsigned short)tmp;
			log_dbg1("Libtcaps: Term size: %hux%hu", tws.ts_cols, tws.ts_lines);
		}
	}
	return (tws);
}

t_cpos	get_cursor_pos(void)
{
	char		*buff;
	t_cpos		cpos;

	ft_bzero(&cpos, sizeof(cpos));
	write(STDIN_FILENO, "\033[6n", 4);
	if ((gnp(STDIN_FILENO, &buff, 'R', 2) == -1) || buff[1] != '[')
		log_fatal("Libtcaps: Failed to read cursor pos from STDIN_FILENO");
	else
	{
		cpos.cp_line = (unsigned short)ft_atoi(&buff[2]);
		cpos.cp_col = (unsigned short)ft_atoi(ft_strchr(buff, ';') + 1);
		log_dbg3("Libtcaps: cursor pos: col: %hu, line: %hu", cpos.cp_col,
																cpos.cp_line);
	}
	return (cpos);
}
