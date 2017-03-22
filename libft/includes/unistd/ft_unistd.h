/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unistd.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:07:00 by chbravo-          #+#    #+#             */
/*   Updated: 2017/03/21 16:07:00 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UNISTD
# define FT_UNISTD
# include <libft.h>

# define GETOPT_ERR_OPT 1
# define GETOPT_ERR_ARG 2

int ft_getopt(int ac, char *const *av, const char *optstring);
/*
int ft_getopt_long(int ac, char * const av[], const char *optstring, const struct option *longopts, int *longindex);
int ft_getopt_long_only(int ac, char * const av[], const char *optstring, const struct option *longopts, int *longindex);
*/

#endif