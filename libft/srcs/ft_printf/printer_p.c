/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 02:58:21 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/31 18:36:57 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <ft_printf/printf_type.h>
#include <ft_printf/printer.h>

int	ft_print_p(int fd, t_args *sarg, va_list *larg)
{
	sarg->alternate = 1;
	sarg->len_modifier = l;
	return (ft_print_x(fd, sarg, larg));
}
