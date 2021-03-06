/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_home_end.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:47:35 by chbravo-          #+#    #+#             */
/*   Updated: 2017/03/30 14:30:38 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tcaps_test.h>

BOOL	exec_home(const t_key *key)
{
	(void)key;
	write(1, "User pressed HOME", 17);
	exec_ctrl_c(key);
	return (false);
}

BOOL	exec_end(const t_key *key)
{
	(void)key;
	write(1, "User pressed END", 16);
	exec_ctrl_c(key);
	return (false);
}
