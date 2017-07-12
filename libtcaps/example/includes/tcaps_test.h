/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 18:02:09 by chbravo-          #+#    #+#             */
/*   Updated: 2017/03/30 14:29:32 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TCAPS_TEST_H
# define TCAPS_TEST_H

#include <libft.h>
#include <libtcaps.h>
#include <types/bool.h>

#define PROGNAME "tcapstest"

typedef struct	s_key_exec
{
	char	*key_code;
	BOOL	(*f)(const t_key *);
}				t_key_exec;

void	raw_terminal_mode(void);
void	default_terminal_mode(void);

BOOL	key_exec(t_key *key);

BOOL	exec_ctrl_c(const t_key *key);
BOOL	exec_ctrl_d(const t_key *key);
BOOL	exec_ctrl_z(const t_key *key);
BOOL	exec_ctrl_a(const t_key *key);
BOOL	exec_ctrl_e(const t_key *key);
BOOL	exec_ctrl_l(const t_key *key);
BOOL	exec_ctrl_j(const t_key *key);
BOOL	exec_ctrl_r(const t_key *key);
BOOL	exec_ctrl_v(const t_key *key);
BOOL	exec_ctrl_w(const t_key *key);

BOOL	exec_backspace(const t_key *key);
BOOL	exec_delete(const t_key *key);
BOOL	exec_insert(const t_key *key);
BOOL	exec_home(const t_key *key);
BOOL	exec_end(const t_key *key);

BOOL	exec_tab(const t_key *key);

BOOL	exec_arrow(const t_key *key);

BOOL	exec_ctrl_left_arrow(const t_key *key);
BOOL	exec_ctrl_right_arrow(const t_key *key);
BOOL	exec_ctrl_up_arrow(const t_key *key);
BOOL	exec_ctrl_down_arrow(const t_key *key);

#endif