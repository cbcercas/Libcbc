/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_insert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 13:48:35 by jlasne            #+#    #+#             */
/*   Updated: 2017/12/12 13:48:37 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tcaps_test.h>

BOOL	exec_insert(const t_key *key)
{
	(void)key;
	write(1, "User pressed insert", 19);
	exec_ctrl_c(key);
	return (false);
}
