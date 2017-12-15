/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_key_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 12:37:13 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/10 14:22:01 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tcaps_test.h>

BOOL	key_exec(t_key *key)
{
	static t_key_exec	fn_exec[] = {
		{KEY_CODE_RARROW, &exec_arrow},
		{KEY_CODE_LARROW, &exec_arrow},
		{KEY_CODE_DARROW, &exec_arrow},
		{KEY_CODE_UARROW, &exec_arrow},
		{KEY_CODE_CTRL_RARROW, &exec_ctrl_right_arrow},
		{KEY_CODE_CTRL_LARROW, &exec_ctrl_left_arrow},
		{KEY_CODE_CTRL_UARROW, &exec_ctrl_up_arrow},
		{KEY_CODE_CTRL_DARROW, &exec_ctrl_down_arrow},
		{KEY_CODE_ALT_RARROW, &exec_alt_right_arrow},
		{KEY_CODE_ALT_LARROW, &exec_alt_left_arrow},
		{KEY_CODE_ALT_UARROW, &exec_alt_up_arrow},
		{KEY_CODE_ALT_DARROW, &exec_alt_down_arrow},
		{KEY_CODE_CTRL_C, &exec_ctrl_c},
		{KEY_CODE_CTRL_D, &exec_ctrl_d},
		{KEY_CODE_CTRL_Z, &exec_ctrl_z},
		{KEY_CODE_CTRL_A, &exec_ctrl_a},
		{KEY_CODE_CTRL_E, &exec_ctrl_e},
		{KEY_CODE_CTRL_L, &exec_ctrl_l},
		{KEY_CODE_ENTER, &exec_ctrl_j},
		{KEY_CODE_CTRL_R, &exec_ctrl_r},
		{KEY_CODE_CTRL_V, &exec_ctrl_v},
		{KEY_CODE_CTRL_W, &exec_ctrl_w},
		{KEY_CODE_INSERT, &exec_insert},
		{KEY_CODE_HOME, &exec_home},
		{KEY_CODE_END, &exec_end},
		{KEY_CODE_DELETE, &exec_delete},
		{KEY_CODE_BACKSPACE, &exec_backspace},
		{KEY_CODE_TAB, &exec_tab},
		{KEY_CODE_ALT_C, &exec_alt_c},
		{KEY_CODE_ALT_I, &exec_alt_i},
		{KEY_CODE_ALT_V, &exec_alt_v},
		{KEY_CODE_ALT_X, &exec_alt_x},
		{KEY_CODE_ALT_S, &exec_alt_s},
		{KEY_CODE_NONE, NULL}
	};
	int					i;

	i = -1;
	while (fn_exec[++i].f != NULL)
		if (ft_strequ(fn_exec[i].key_code, key->key_code))
			return (fn_exec[i].f(key));
	return (false);
}
