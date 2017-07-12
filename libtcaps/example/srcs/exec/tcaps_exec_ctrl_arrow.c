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

BOOL	exec_ctrl_left_arrow(const t_key *key)
{
	(void)key;
	log_dbg1("exec ctrl+left arrow.");
	write(1, "User pressed ctrl + left arrow", 30);
	exec_ctrl_c(key);
	return (false);
}

BOOL	exec_ctrl_right_arrow(const t_key *key)
{
	(void)key;
	log_dbg1("exec ctrl+right arrow.");
	write(1, "User pressed ctrl + right arrow", 31);
	exec_ctrl_c(key);
	return (false);
}

BOOL	exec_ctrl_up_arrow(const t_key *key)
{
	(void)key;
	log_dbg1("exec ctrl+up arrow.");
	write(1, "User pressed ctrl + up arrow", 28);
	exec_ctrl_c(key);
	return (false);
}

BOOL	exec_ctrl_down_arrow(const t_key *key)
{
	(void)key;
	log_dbg1("exec ctrl+down arrow.");
	write(1, "User pressed ctrl + down arrow", 30);
	exec_ctrl_c(key);
	return (false);
}