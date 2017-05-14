/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 03:38:16 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/31 18:33:10 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_H
# define FT_GET_H
# include <stdarg.h>
# include <intern/printf_type.h>

char	*ft_get_flags(char **format, t_args	*sargs);
char	*ft_get_width(char **format, t_args *sargs, va_list *args);
char	*ft_get_precision(char **format, t_args *sargs, va_list *args);
char	*ft_get_len_modifier(char **format, t_args *sargs);
char	*ft_get_conversion(char **format, t_args *sargs);

#endif
