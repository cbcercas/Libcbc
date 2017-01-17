/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 02:58:21 by chbravo-          #+#    #+#             */
/*   Updated: 2016/11/18 03:32:26 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_H
# define PRINTER_H
# include <stdarg.h>
# include "type.h"

int	ft_print_c(t_args *sarg, va_list *larg);
int	ft_print_wc(t_args *sarg, va_list *larg);
int	ft_print_d(t_args *sarg, va_list *larg);
int	ft_print_o(t_args *sarg, va_list *larg);
int	ft_print_p(t_args *sarg, va_list *larg);
int	ft_print_s(t_args *sarg, va_list *larg);
int	ft_print_ws(t_args *sarg, va_list *larg);
int	ft_print_u(t_args *sarg, va_list *larg);
int	ft_print_x(t_args *sarg, va_list *larg);
int	ft_print_wx(t_args *sarg, va_list *larg);
int	ft_print_per(t_args *sarg, va_list *larg);
int	ft_print_def(t_args *sarg, va_list *larg);

#endif
