/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 03:33:55 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/13 21:16:55 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_UTILS_H
# define PRINTF_UTILS_H
# include <stdarg.h>
# include <intern/printf_type.h>
# include <inttypes.h>
# include <stdlib.h>

int			ft_print_pad(int fd, int len_res, int pad, char c);
intmax_t	ft_signed_from_lenght(t_args *sarg, intmax_t nb);
uintmax_t	ft_unsigned_from_lenght(t_args *sarg, uintmax_t nb);
void		put_uprecision(t_args *s, size_t *len, char **nbr);
int			ft_print(int fd, va_list *larg, const char *fmt, int printed);

#endif
