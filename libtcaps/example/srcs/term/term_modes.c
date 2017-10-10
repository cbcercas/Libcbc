/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_modes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 12:38:28 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/10 14:21:09 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <tcaps_test.h>

void	raw_terminal_mode(void)
{
	struct termios	tattr;

	tcgetattr(STDIN_FILENO, &tattr);
	tattr.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	tattr.c_oflag &= ~(OPOST);
	tattr.c_cc[VMIN] = 1;
	tattr.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr);
	tgetent(NULL, getenv("TERM"));

	return;
}

void	default_terminal_mode(void)
{
	struct termios	tattr;

	tcgetattr(STDIN_FILENO, &tattr);
	tattr.c_lflag |= (ECHO | ICANON | IEXTEN | ISIG);
	tattr.c_oflag |= ( OPOST);
	tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr);

	return;
}
