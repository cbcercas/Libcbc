/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unistd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:08:00 by chbravo-          #+#    #+#             */
/*   Updated: 2017/03/21 16:08:00 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd/ft_unistd.h>
#include <ft_printf/libftprintf.h>

int		g_opterr = 1;
int		g_optind = 1;
int		g_optopt;
int		g_optreset;
char	*g_optarg;

static int	get_char(char const *av)
{
	static const char	*nextchar = NULL;
	const char			*opt;

	if (nextchar)
		opt = nextchar;
	else
		opt = av + 1;
	if (*(opt + 1))
		nextchar = opt + 1;
	else
	{
		nextchar = NULL;
		g_optind += 1;
	}
	return ((int)*opt);
}

int 		ft_getopt(int ac, char const *av[], const char *optstring)
{
	(void)optstring;
	int	opt;

	if (g_optind >= ac || !ft_strncmp(av[g_optind], "--", 2) || av[g_optind][0] != '-')
		return (-1);
	opt = get_char(av[g_optind]);
	if (ft_isalnum(opt) && ft_strchr(optstring, opt))
		return (opt);
	if (g_opterr)
		ft_printf("%s: invalid option -- '%c'\n", av[0], opt);
	return ('?');
};

/*int ft_getopt_long(int ac, char * const av[], const char *optstring, const struct option *longopts, int *longindex)
{

};

int ft_getopt_long_only(int ac, char * const av[], const char *optstring, const struct option *longopts, int *longindex)
{

};*/
