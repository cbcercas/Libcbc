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
char	*g_optarg;

static int	go_init(int ac, char *const *av)
{
	if (g_optind >= ac
		|| ft_strequ(av[g_optind], "--")
		|| av[g_optind][0] != '-'
		|| ft_strequ(av[g_optind], "-"))
		return (-1);
	g_optopt = 0;
	return (0);
}

static const char	*go_char(const char **nextchar, char *const *av)
{
	const char *opt;

	g_optarg = NULL;
	if (*nextchar)
		opt = *nextchar;
	else
		opt = av[g_optind] + 1;
	if (*(opt + 1))
		*nextchar = opt + 1;
	else
	{
		*nextchar = NULL;
		g_optind += 1;
	}
	return (opt);
}

static int		go_err(int err, const char *c,const char *av, const char o)
{
	g_optopt = (int)o;
	{
		if (err == GETOPT_ERR_ARG)
		{
			if (g_opterr && *c != ':')
				ft_dprintf(STDERR_FILENO, "%s: option requires an argument -- '%c'\n", av, o);
			else
				return (':');
		}
		else if (err == GETOPT_ERR_OPT)
			if (g_opterr && *c != ':')
				ft_dprintf(STDERR_FILENO, "%s: invalid option -- '%c'\n", av, o);
	}
	return ('?');
}

int 		ft_getopt(int ac, char *const *av, const char *optstring)
{
	static const char	*nextchar = NULL;
	const char			*opt;
	const char 			*c;

	if (go_init(ac, av))
		return (-1);
	opt = go_char(&nextchar, av);
	if (ft_isalnum(*opt) && (c = ft_strchr(optstring, *opt)))
	{
		if (*(c + 1) == ':')
		{
			if (*(opt + 1) != '\0')
				g_optarg = (char *) (opt + 1);
			else if (g_optind < ac)
				g_optarg = (char *) av[g_optind];
			else
				return (go_err(GETOPT_ERR_ARG, optstring, av[0], *opt));
			g_optind += 1;
			nextchar = NULL;
		}
		return ((int) *opt);
	}
	return (go_err(GETOPT_ERR_OPT, optstring, av[0], *opt));
};
