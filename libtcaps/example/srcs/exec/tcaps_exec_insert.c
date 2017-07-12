/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_inset.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:47:35 by chbravo-          #+#    #+#             */
/*   Updated: 2017/03/30 14:30:38 by jlasne           ###   ########.fr       */
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
