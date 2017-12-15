/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 02:58:21 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/13 15:24:48 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_H
# define PRINTER_H
# include <stdarg.h>
# include <intern/printf_type.h>

int	ft_print_c(int fd, t_args *sarg, va_list *larg);
int	ft_print_wc(int fd, t_args *sarg, va_list *larg);
int	ft_print_d(int fd, t_args *sarg, va_list *larg);
int	ft_print_o(int fd, t_args *sarg, va_list *larg);
int	ft_print_p(int fd, t_args *sarg, va_list *larg);
int	ft_print_s(int fd, t_args *sarg, va_list *larg);
int	ft_print_ws(int fd, t_args *sarg, va_list *larg);
int	ft_print_u(int fd, t_args *sarg, va_list *larg);
int	ft_print_x(int fd, t_args *sarg, va_list *larg);
int	ft_print_wx(int fd, t_args *sarg, va_list *larg);
int	ft_print_per(int fd, t_args *sarg, va_list *larg);
int	ft_print_def(int fd, t_args *sarg, va_list *larg);

#endif
