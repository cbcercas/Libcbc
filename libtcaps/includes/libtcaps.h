/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtcaps.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 14:38:32 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/10 13:31:21 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CBC_TERMCAPS_H
# define CBC_TERMCAPS_H

# include <termios.h>
# include <curses.h>
# include <term.h>

# include <libft.h>
# include <types/bool.h>
# include <ftprintf.h>
# include <logger.h>
# include <gnl/get_next_line.h>
# include <sys/ioctl.h>

/**
** @struct     s_ts
**
** @brief      This struct is the terminal size
**
** @var        s_ts::ts_cols
**                   The column number
** @var        s_ts::ts_lines
**                   The line number
*/
typedef struct s_ts	t_ts;
struct	s_ts
{
	unsigned short ts_cols;
	unsigned short ts_lines;
};

t_ts	get_term_size(void);

/**
** @struct     s_ts
**
** @brief      This struct is the terminal size
**
** @var        s_cpos::cp_col
**                   The column position
** @var        s_cpos::cp_line
**                   The line position
*/
typedef struct s_cpos t_cpos;
struct s_cpos
{
	unsigned short cp_col;
	unsigned short cp_line;
};

/**
** @file       tcaps_size.c
**
** @brief      cursor position and teminal size.
**
** @return     get_cursor_pos return struct s_cpos
**             get_term_size return struct s_ts,
**             On error structs are filled with 0.
*/
t_cpos	get_cursor_pos(void);
t_ts	get_term_size(void);

# define MAX_KEY_STRING_LEN 10

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
# define KEY_CODE_CTRL_R "\x12\0\0\0\0"
# define KEY_CODE_CTRL_V "\x16\0"
# define KEY_CODE_CTRL_W "\x17\0"
# define KEY_CODE_CTRL_UARROW "\x1B\x5B\x31\x3B\x35\x41\0"
# define KEY_CODE_CTRL_DARROW "\x1B\x5B\x31\x3B\x35\x42\0"
# define KEY_CODE_CTRL_RARROW "\x1B\x5B\x31\x3B\x35\x43\0"
# define KEY_CODE_CTRL_LARROW "\x1B\x5B\x31\x3B\x35\x44\0"
# define KEY_CODE_ALT_UARROW "\x1B\x1B\x5B\x41\0"
# define KEY_CODE_ALT_DARROW "\x1B\x1B\x5B\x42\0"
# define KEY_CODE_ALT_RARROW "\x1B\x1B\x5B\x43\0"
# define KEY_CODE_ALT_LARROW "\x1B\x1B\x5B\x44\0"
# define KEY_CODE_BACKSPACE "\x7F\0"
# define KEY_CODE_DELETE "kD"
# define KEY_CODE_TAB "\x9\0\0\0\0"
# define KEY_CODE_ENTER "\xA\0\0\0\0"
# define KEY_CODE_END "\x1b\x5b\x46\0"
# define KEY_CODE_HOME "\x1b\x5b\x48\0"
# define KEY_CODE_INSERT "kI"

# define KEY_CODE_ALT_S "\xC3\x9F\0"

# define KEY_CODE_ALT_C "\xC3\xA7\0"
# define KEY_CODE_ALT_I "\xCB\x86\0"
# define KEY_CODE_ALT_V "\xE2\x88\x9a\0"
# define KEY_CODE_ALT_X "\xE2\x89\x88\0"

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
*/
t_key	key_new(char *key_code, const char *buff);
t_key	key_get(const char *buff, BOOL tcaps_activ);
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
** @file       tcaps_ctrl_arrow.c
**
** @brief      Determines if ctrl+arrow.
**
** @param[in]  buff  The buffer
**
** @return     True if ctrl+arrow, False otherwise.
*/
BOOL	is_ctrl_right_arrow(const char *buff);
BOOL	is_ctrl_left_arrow(const char *buff);
BOOL	is_ctrl_up_arrow(const char *buff);
BOOL	is_ctrl_down_arrow(const char *buff);

/**
** @file       tcaps_alt_arrow.c
**
** @brief      Determines if alt+arrow.
**
** @param[in]  buff  The buffer
**
** @return     True if alt+arrow, False otherwise.
*/
BOOL	is_alt_right_arrow(const char *buff);
BOOL	is_alt_left_arrow(const char *buff);
BOOL	is_alt_up_arrow(const char *buff);
BOOL	is_alt_down_arrow(const char *buff);


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

/**
** @file		tcaps_ctrl_2.c
**
** @brief		Determines if crtl+*.
**
** @param[in]	buff  The buffer
**
** @return True if control, False otherwise
*/

BOOL	is_ctrl_l(const char *buff);
BOOL	is_ctrl_j(const char *buff);
BOOL    is_ctrl_r(const char *buff);
BOOL    is_ctrl_v(const char *buff);
BOOL    is_ctrl_w(const char *buff);

/**
** @file tcaps_backspace.c
**
** @brief Determines if backspace is pressed
**
** @param[in]	buff  The buffer
**
** @return True if control, False otherwise
*/

BOOL	is_backspace(const char *buff);

/**
** @file tcaps_delete.c
**
** @brief Determines if delete is pressed
**
** @param[in]	buff  The buffer
**
** @return True if control, False otherwise
*/

BOOL	is_delete(const char *buff);

/**
** @file tcaps_tab.c
**
** @brief Determines if tab is pressed
**
** @param[in]	buff  The buffer
**
** @return True if control, False otherwise
*/

BOOL	is_tab(const char *buff);

/**
** @file tcaps_home_end.c
**
** @brief Determines if home or end is pressed
**
** @param[in]	buff  The buffer
**
** @return True if true, False otherwise
*/
BOOL    is_home(const char *buff);
BOOL    is_end(const char *buff);

/**
** @file tcaps_insert.c
**
** @brief Determines if insert pressed
**
** @param[in]	buff  The buffer
**
** @return True if insert, False otherwise
*/
BOOL	is_insert(const char *buff);

/**
** @file tcaps_alt.c
**
** @brief Determines if alt combination pressed
**
** @param[in]	buff  The buffer
**
** @return True if true, False otherwise
*/
BOOL	is_alt_c(const char *buff);
BOOL	is_alt_i(const char *buff);
BOOL	is_alt_v(const char *buff);
BOOL	is_alt_x(const char *buff);
BOOL	is_alt_s(const char *buff);

/**
** @file tcaps_moving.c
**
** @brief moving cursor
**
** @param[in]	cpos  The cursor position
** @param[in]	ts    The teminal size
*/
void	move_cursor_left(t_cpos *cpos, struct winsize *ts);
void	move_cursor_right(t_cpos *cpos, struct winsize *ts);

#endif
