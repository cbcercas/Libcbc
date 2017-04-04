/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtcaps.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 14:38:32 by chbravo-          #+#    #+#             */
/*   Updated: 2017/03/30 13:50:36 by jlasne           ###   ########.fr       */
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

# define MAX_KEY_STRING_LEN 3

# define KEY_CODE_RARROW "kr"
# define KEY_CODE_LARROW "kl"
# define KEY_CODE_DARROW "kd"
# define KEY_CODE_UARROW "ku"
# define KEY_CODE_CTRL_C "\x3\0\0\0\0\0"
# define KEY_CODE_CTRL_D "\x4\0\0\0\0\0"
# define KEY_CODE_CTRL_Z "\x1A\0\0\0\0"
# define KEY_CODE_CTRL_A "\x01\0\0\0\0"
# define KEY_CODE_CTRL_E "\x05\0\0\0\0"
# define KEY_CODE_CTRL_L "\x0C\0\0\0\0"
# define KEY_CODE_BACKSPACE "\x8\0\0\0\0"
# define KEY_CODE_TAB "\x9\0\0\0\0"
# define KEY_CODE_OTHER ""
# define KEY_CODE_NONE ""

typedef struct	s_key		t_key;
typedef struct	s_key_test	t_key_test;

/**
** @struct     s_key
**
** @brief      This struct is used to define a key
**
** @var        s_key::key_code
**                   The keycode for the key
** @var        s_key::key
**                   A copy of the key read
*/
struct	s_key
{
	char	*key_code;
	char	key[MAX_KEY_STRING_LEN];
};

/**
** @struct     s_key_test
**
** @brief      This struct is used in the key_get function,
**             to define the test function for a key
**
** @var        s_key_test::key_code
**                        The keycode for the key
** @var        s_key_test::f
**                        A pointer to the test function
*/
struct	s_key_test
{
	char	*key_code;
	BOOL	(*f)(const char *);
}				;

/**
** @file       tcaps_utils.c
**
** @brief      Main tcaps function
**             key_new create a t_key from key_code and the buff read
**             key_get get the t_key from buff
**             key_del clean a t_key
**
** @param      key_code  The key code
** @param[in]  buff      The buffer
**
** @return     key_new and key_get return a t_key
**/
t_key	key_new(char *key_code, const char *buff);
t_key	key_get(const char *buff);
void	key_del(t_key *key);

/**
** @file       tcaps_arrow.c
**
** @brief      Determines if arrow.
**
** @param[in]  buff  The buffer
**
** @return     True if arrow, False otherwise.
*/
BOOL	is_right_arrow(const char *buff);
BOOL	is_left_arrow(const char *buff);
BOOL	is_down_arrow(const char *buff);
BOOL	is_up_arrow(const char *buff);

/**
** @file       tcaps_ctrl_1.c
**
** @brief      Determines if ctrl+*.
**
** @param[in]  buff  The buffer
**
** @return     True if control, False otherwise.
*/
BOOL	is_ctrl_c(const char *buff);
BOOL	is_ctrl_d(const char *buff);
BOOL	is_ctrl_z(const char *buff);
BOOL	is_ctrl_a(const char *buff);
BOOL	is_ctrl_e(const char *buff);

/*
** @file		tcaps_ctrl_1.c
**
** @brief		Determines if crtl+*.
**
** @param[in]	buff  The buffer
**
** @return True if control, False otherwise
*/

BOOL	is_ctrl_l(const char *buff);

/*
** @file tcaps_backspace.c
**
** @brief Determines if backspace is pressed
**
** @param[in]	buff  The buffer
**
** @return True if control, False otherwise
*/

BOOL	is_backspace(const char *buff);

/*
** @file tcaps_tab.c
**
** @brief Determines if tab is pressed
**
** @param[in]	buff  The buffer
**
** @return True if control, False otherwise
*/

BOOL	is_tab(const char *buff);

#endif
