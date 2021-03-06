/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_ctrl_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:47:35 by chbravo-          #+#    #+#             */
/*   Updated: 2017/03/30 14:30:38 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tcaps_test.h>

BOOL	exec_ctrl_j(const t_key *key)
{
	(void)key;
	write(1, "User pressed CTRL+J\n", 20);
	exec_ctrl_c(key);
	return (false);
}

BOOL	exec_ctrl_r(const t_key *key)
{
	(void)key;
	write(1, "User pressed CTRL+R\n", 19);
	exec_ctrl_c(key);
	return (false);
}

BOOL	exec_ctrl_v(const t_key *key)
{
	(void)key;
	write(1, "User pressed CTRL+V", 19);
	exec_ctrl_c(key);
	return (false);
}

BOOL	exec_ctrl_w(const t_key *key)
{
	(void)key;
	write(1, "User pressed CTRL+W", 19);
	exec_ctrl_c(key);
	return (false);
}

BOOL	exec_ctrl_l(const t_key *key)
{
	(void)key;
	write(1, "User pressed CTRL+L\n", 20);
	exec_ctrl_c(key);
	return (false);
}
