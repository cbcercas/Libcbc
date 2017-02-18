/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtcaps.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 14:38:32 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/18 12:41:19 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CBC_TERMCAPS_H
# define CBC_TERMCAPS_H
# include <termios.h>
# include <curses.h>
# include <term.h>

# include <libft.h>
# include <types/bool.h>
# include <ft_printf/libftprintf.h>

# define KEY_CODE_RARROW "kr"
# define KEY_CODE_LARROW "kl"
# define KEY_CODE_DARROW "kd"
# define KEY_CODE_UARROW "ku"
# define KEY_CODE_CTRL_C "\x3\0\0\0\0\0"
# define KEY_CODE_CTRL_D "\x4\0\0\0\0\0"
# define KEY_CODE_OTHER ""
# define KEY_CODE_NONE ""

# define MAX_KEY_STRING_LEN 3

typedef struct	s_key
{
	char	*key_code;
	char	key[MAX_KEY_STRING_LEN];
}				t_key;

typedef struct	s_key_test
{
	char	*key_code;
	BOOL	(*f)(const char *);
}				t_key_test;

t_key	key_new(char *key_code, const char *buff);
t_key	key_get(const char *buff);
void	key_del(t_key *key);

BOOL	is_right_arrow(const char *buff);
BOOL	is_left_arrow(const char *buff);
BOOL	is_down_arrow(const char *buff);
BOOL	is_up_arrow(const char *buff);

BOOL	is_ctrl_c(const char *buff);
BOOL	is_ctrl_d(const char *buff);

#endif