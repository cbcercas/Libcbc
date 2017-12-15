/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 14:37:43 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/10 14:28:45 by jlasne           ###   ########.fr       */
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

	raw_terminal_mode();
	logger_init(D_MAX - 1, PROGNAME, "test.log");
	stop = false;
	while (stop == false)
	{
		raw_terminal_mode();
		(void)ft_bzero((void *)buff, MAX_KEY_STRING_LEN);
		res = read(STDIN_FILENO, buff, MAX_KEY_STRING_LEN);
		buff[res] = '\0';
		key = key_get(buff, true);
		default_terminal_mode();
		ft_printf("%x\n", buff[0]);
		ft_printf("%x\n", buff[1]);
		ft_printf("%x\n", buff[2]);
		ft_printf("%x\n", buff[3]);
		ft_printf("%x\n", buff[4]);
		ft_printf("%x\n", buff[5]);
		ft_printf("%x\n", buff[6]);
		ft_printf("%x\n", buff[7]);
		ft_printf("%x\n", buff[8]);
		ft_printf("%x\n\n", buff[9]);

		/*	if (ft_strcmp(key.key_code, KEY_CODE_NONE))
			stop = key_exec(&key);
			else
			if (ft_isprint(key.key[0]))
			ft_printf("%c", key.key[0]);*/

		key_del(&key);
		if (stop == false && i++ == 20)
			stop = true;
	}
	tputs(tgetstr("cl", NULL), 0, &ft_putc_in);
	default_terminal_mode();
	logger_close();
	return 0;
}
