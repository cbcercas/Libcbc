/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unistd.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:07:00 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/13 15:50:07 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UNISTD_H
# define FT_UNISTD_H

# ifndef LOGGER_MAIN
#  include <libft.h>
#  include <ft_printf/libftprintf.h>
#  define GETOPT_ERR_OPT 1
#  define GETOPT_ERR_ARG 2
# endif

int ft_getopt(int ac, char *const *av, const char *optstring);

#endif
