/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_backspace.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 13:04:39 by chbravo-          #+#    #+#             */
/*   Updated: 2017/03/30 13:41:30 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tcaps_test.h>

BOOL	exec_backspace(const t_key *key)
{
	(void)key;
	write(1, "User pressed backspace\n", 22);
	exec_ctrl_c(key);
	return (false);
}

BOOL	exec_delete(const t_key *key)
{
	(void)key;
	write(1, "User pressed delete", 19);
	exec_ctrl_c(key);
	return (false);
}
