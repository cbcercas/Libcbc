/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 03:43:38 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/31 18:42:06 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <ft_printf/printf_type.h>
#include <ft_printf/libftprintf.h>

int		ft_get_args(char **format, va_list *larg, t_args *sarg)
{
	if (*++*format == '\0')
		return (0);
	if (((*format) = ft_get_flags(format, sarg)) == NULL)
		return (-1);
	if (((*format) = ft_get_width(format, sarg, larg)) == NULL)
		return (-1);
	if (((*format) = ft_get_precision(format, sarg, larg)) == NULL)
		return (-1);
	if (((*format) = ft_get_len_modifier(format, sarg)) == NULL)
		return (-1);
	if (((*format) = ft_get_conversion(format, sarg)) == NULL)
		return (-1);
	return (0);
}

int		ft_print_args(int fd, t_args *sarg, va_list *larg)
{
	int	(*print[12])(int fd, t_args *sarg, va_list *larg);

	print[0] = ft_print_c;
	print[1] = ft_print_wc;
	print[2] = ft_print_d;
	print[3] = ft_print_o;
	print[4] = ft_print_p;
	print[5] = ft_print_s;
	print[6] = ft_print_ws;
	print[7] = ft_print_u;
	print[8] = ft_print_x;
	print[9] = ft_print_wx;
	print[10] = ft_print_per;
	print[11] = ft_print_def;
	if ((sarg->conversion >= c) && (sarg->conversion <= def))
		return (print[(sarg->conversion - 1)](fd, sarg, larg));
	else
		return (0);
}

int		ft_print(int fd, va_list *larg, const char *format, int printed)
{
	char	*next_arg;
	t_args	sarg;
	int		ret;

	next_arg = ft_strchr(format, '%');
	if (!next_arg)
	{
		ft_putstr_fd(format, fd);
		return (printed + ft_strlen(format));
	}
	else if (next_arg > format)
	{
		ft_putnstr_fd(format, next_arg - format, fd);
		return (ft_print(fd, larg, next_arg, printed + (next_arg - format)));
	}
	else
	{
		ft_bzero(&sarg, sizeof(sarg));
		if ((ret = ft_get_args(&(next_arg), larg, &sarg)))
			return (ret);
		if ((ret = ft_print_args(fd, &sarg, larg)) == -1)
			return (-1);
		return (ft_print(fd, larg, next_arg, printed + ret));
	}
}

int		ft_printf(const char *restrict format, ...)
{
	int		ret;
	va_list larg;

	va_start(larg, format);
	ret = ft_print(STDOUT_FILENO, &larg, format, 0);
	return (ret);
}

int		ft_dprintf(int fd, const char *restrict format, ...)
{
	int		ret;
	va_list larg;

	va_start(larg, format);
	ret = ft_print(fd, &larg, format, 0);
	return (ret);
}