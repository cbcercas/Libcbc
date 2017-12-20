/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unistd.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:07:00 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/19 05:39:32 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UNISTD_H
# define FT_UNISTD_H

# ifdef FT_GETOPT_MAIN
#  include <libft.h>
#  define GETOPT_ERR_OPT 1
#  define GETOPT_ERR_ARG 2
# endif

int		ft_getopt(int ac, char *const av[], const char *optstring);
void	ft_getopt_reset(void);

#endif
