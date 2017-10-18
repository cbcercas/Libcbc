/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_ctrl_arrow.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:57:33 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/17 18:50:10 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <tcaps_test.h>

BOOL	exec_alt_left_arrow(const t_key *key)
{
	(void)key;
	log_dbg1("exec alt+left arrow.");
	write(1, "User pressed alt + left arrow", 29);
	exec_ctrl_c(key);
	return (false);
}

BOOL	exec_alt_right_arrow(const t_key *key)
{
	(void)key;
	log_dbg1("exec alt+right arrow.");
	write(1, "User pressed alt + right arrow", 30);
	exec_ctrl_c(key);
	return (false);
}

BOOL	exec_alt_up_arrow(const t_key *key)
{
	(void)key;
	log_dbg1("exec alt+up arrow.");
	write(1, "User pressed alt + up arrow", 27);
	exec_ctrl_c(key);
	return (false);
}

BOOL	exec_alt_down_arrow(const t_key *key)
{
	(void)key;
	log_dbg1("exec alt+down arrow.");
	write(1, "User pressed alt + down arrow", 29);
	exec_ctrl_c(key);
	return (false);
}
