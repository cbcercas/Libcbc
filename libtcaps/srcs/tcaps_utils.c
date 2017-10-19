/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 21:44:30 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/19 06:00:41 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtcaps.h>

t_key	key_new(char *key_code, const char *buff)
{
	t_key	key;

	ft_bzero(&key, sizeof(key));
	key.key_code = key_code;
	ft_memcpy(&key.key, buff, MAX_KEY_STRING_LEN);
	return (key);
}

t_key	key_get(const char *buff, BOOL tcaps_activ)
{
	int					i;
	static t_key_test	fn_test[] = {
		{KEY_CODE_ENTER, &is_ctrl_j},
		{KEY_CODE_RARROW, &is_right_arrow},
		{KEY_CODE_LARROW, &is_left_arrow},
		{KEY_CODE_DARROW, &is_down_arrow},
		{KEY_CODE_UARROW, &is_up_arrow},
		{KEY_CODE_CTRL_C, &is_ctrl_c},
		{KEY_CODE_CTRL_D, &is_ctrl_d},
		{KEY_CODE_CTRL_Z, &is_ctrl_z},
		{KEY_CODE_CTRL_A, &is_ctrl_a},
		{KEY_CODE_CTRL_E, &is_ctrl_e},
		{KEY_CODE_CTRL_L, &is_ctrl_l},
		{KEY_CODE_CTRL_R, &is_ctrl_r},
		{KEY_CODE_CTRL_V, &is_ctrl_v},
		{KEY_CODE_CTRL_W, &is_ctrl_w},
		{KEY_CODE_CTRL_RARROW, &is_ctrl_right_arrow},
		{KEY_CODE_CTRL_LARROW, &is_ctrl_left_arrow},
		{KEY_CODE_CTRL_UARROW, &is_ctrl_up_arrow},
		{KEY_CODE_CTRL_DARROW, &is_ctrl_down_arrow},
		{KEY_CODE_ALT_RARROW, &is_alt_right_arrow},
		{KEY_CODE_ALT_LARROW, &is_alt_left_arrow},
		{KEY_CODE_ALT_UARROW, &is_alt_up_arrow},
		{KEY_CODE_ALT_DARROW, &is_alt_down_arrow},
		{KEY_CODE_BACKSPACE, &is_backspace},
		{KEY_CODE_DELETE, &is_delete},
		{KEY_CODE_TAB, &is_tab},
		{KEY_CODE_HOME, &is_home},
		{KEY_CODE_END, &is_end},
		{KEY_CODE_INSERT, &is_insert},
		{KEY_CODE_ALT_C, &is_alt_c},
		{KEY_CODE_ALT_I, &is_alt_i},
		{KEY_CODE_ALT_V, &is_alt_v},
		{KEY_CODE_ALT_X, &is_alt_x},
		{KEY_CODE_ALT_S, &is_alt_s},
		{KEY_CODE_NONE, NULL}
	};

	if (tcaps_activ)
	{
		i = -1;
		while (fn_test[++i].f != NULL)
		{
			if (fn_test[i].f(buff))
				return (key_new(fn_test[i].key_code, buff));
		}
	}
	else if ('\n' == buff[0])
		return (key_new(KEY_CODE_ENTER, buff));
	return (key_new(KEY_CODE_OTHER, buff));
}

void	key_del(t_key *key)
{
	ft_bzero(key, sizeof(*key));
}
