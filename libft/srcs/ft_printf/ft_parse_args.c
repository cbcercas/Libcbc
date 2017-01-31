/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 03:39:50 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/31 18:42:15 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <ft_printf/printf_type.h>

char		*ft_get_flags(char **format, t_args *sarg)
{
	if (**format == '#' || **format == '0' || **format == '-'
		|| **format == ' ' || **format == '+')
	{
		if (**format == '#')
			sarg->alternate = 1;
		else if (**format == '0')
			sarg->zero_pad = 1;
		else if (**format == '-')
			sarg->left_pad = 1;
		else if (**format == ' ')
			sarg->blank_pos = 1;
		else if (**format == '+')
		{
			sarg->sign_pos = 1;
			sarg->blank_pos = 0;
		}
		(*format)++;
		return (ft_get_flags(format, sarg));
	}
	return (*format);
}

char		*ft_get_width(char **format, t_args *sarg, va_list *larg)
{
	if (**format == '*' || ft_isdigit(**format))
	{
		if (ft_isdigit(**format))
		{
			sarg->min_width = ((sarg->min_width) * 10) + ((**format) - '0');
			(*format)++;
			(*format) = ft_get_width(format, sarg, larg);
		}
		else
		{
			sarg->min_width = va_arg(*larg, int);
			(*format)++;
		}
	}
	return (*format);
}

char		*ft_get_precision(char **format, t_args *sarg, va_list *larg)
{
	if (**format == '.' || ft_isdigit(**format))
	{
		sarg->precision = 1;
		if (ft_isdigit(**format))
		{
			sarg->preci_len = (sarg->preci_len * 10) + ((**format) - '0');
			(*format)++;
			(*format) = ft_get_precision(format, sarg, larg);
		}
		else
		{
			(*format)++;
			sarg->preci_len = 0;
			(*format) = ft_get_precision(format, sarg, larg);
		}
	}
	return (*format);
}

char		*ft_get_len_modifier(char **format, t_args *sarg)
{
	if (**format == 'h' && *(*format + 1) == 'h')
	{
		sarg->len_modifier = hh;
		(*format)++;
	}
	else if (**format == 'l' && *(*format + 1) == 'l')
	{
		sarg->len_modifier = ll;
		(*format)++;
	}
	else if (**format == 'h')
		sarg->len_modifier = h;
	else if (**format == 'l')
		sarg->len_modifier = l;
	else if (**format == 'j')
		sarg->len_modifier = j;
	else if (**format == 'z')
		sarg->len_modifier = z;
	else
		return (*format);
	(*format)++;
	return (*format);
}
