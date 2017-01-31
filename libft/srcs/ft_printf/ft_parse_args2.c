/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 03:55:12 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/31 18:34:10 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf/printf_type.h>

static char	*ft_get_conversion2(char **format, t_args *sarg)
{
	if (**format == 'u' || **format == 'U')
	{
		sarg->conversion = u;
		if (**format == 'U')
			sarg->len_modifier = l;
	}
	else if (**format == 'x')
		sarg->conversion = x;
	else if (**format == 'X')
		sarg->conversion = X;
	else if (**format == 'c')
		sarg->conversion = c;
	else if (**format == 'C')
		sarg->conversion = C;
	else if (**format == '%')
		sarg->conversion = per;
	else
	{
		sarg->conversion = def;
		sarg->defchar = **format;
	}
	(*format)++;
	return (*format);
}

char		*ft_get_conversion(char **format, t_args *sarg)
{
	if (**format == 's')
		sarg->conversion = s;
	else if (**format == 'S')
		sarg->conversion = S;
	else if (**format == 'p')
		sarg->conversion = p;
	else if (**format == 'd' || **format == 'D' || **format == 'i')
	{
		sarg->conversion = d;
		if (**format == 'D')
			sarg->len_modifier = l;
	}
	else if (**format == 'o')
		sarg->conversion = o;
	else if (**format == 'o' || **format == 'O')
	{
		sarg->conversion = o;
		if (**format == 'O')
			sarg->len_modifier = l;
	}
	else
		return (ft_get_conversion2(format, sarg));
	(*format)++;
	return (*format);
}
