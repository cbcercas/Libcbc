/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_alt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 12:37:13 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/10 14:21:02 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tcaps_test.h>

BOOL	exec_alt_c(const t_key *key)
{
	(void)key;
	write(1, "User pressed ALT+C", 18);
	exec_ctrl_c(key);
	return (false);
}

BOOL	exec_alt_i(const t_key *key)
{
	(void)key;
	write(1, "User pressed ALT+I", 18);
	exec_ctrl_c(key);
	return (false);
}

BOOL	exec_alt_v(const t_key *key)
{
	(void)key;
	write(1, "User pressed ALT+V", 18);
	exec_ctrl_c(key);
	return (false);
}

BOOL	exec_alt_x(const t_key *key)
{
	(void)key;
	write(1, "User pressed ALT+X", 18);
	exec_ctrl_c(key);
	return (false);
}

BOOL	exec_alt_s(const t_key *key)
{
	(void)key;
	write(1, "User pressed ALT+S", 18);
	exec_ctrl_c(key);
	return (false);
}
