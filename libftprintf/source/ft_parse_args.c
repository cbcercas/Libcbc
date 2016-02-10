#include "libft.h"
#include "libftprintf.h"

char	*ft_get_flags(char **format, t_args	*sargs)
{
	if (**format == '#' || **format == '0' || **format == '-'
		|| **format == ' ' || **format == '+' || **format == 103)
	{
		
		if (**format == '#')
			sargs->alternate = 1;
		else if (**format == '0')
			sargs->zero_pad = 1;
		else if (**format == '-')
			sargs->left_pad = 1;
		else if (**format == ' ' && !sargs->sign_pos)
			sargs->blank_pos = 1;
		else if (**format == '+')
		{
			sargs->sign_pos = 1;
			sargs->blank_pos = 0;
		}
		else if (**format == 103)
			sargs->deci_conv = 1;
		(*format)++;
		return(ft_get_flags(format, sargs));
	}
	return(*format);
}

char *ft_get_width(char **format, t_args *sargs, va_list *args)
{
	if (**format == '*' || ft_isdigit(**format))
	{
		if (ft_isdigit(**format))
		{
			sargs->min_width = ((sargs->min_width) * 10) + ((**format) - '0');
			(*format)++;
			(*format) = ft_get_width(format, sargs, args);
		}
		else
		{
			sargs->min_width = va_arg(args, int);
			(*format)++;
		}
	}
	return (*format);
}

char *ft_get_precision(char **format, t_args *sargs, va_list *args)
{
	if (**format == '.' || ft_isdigit(**format))
	{
		if (ft_isdigit(**format))
		{
			sargs->precision = ((sargs->precision) * 10) + ((**format) - '0');
			(*format)++;
			(*format) = ft_get_precision(format, sargs, args);
		}
		else
		{
			(*format)++;
			sargs->precision = 0;
			(*format) = ft_get_precision(format, sargs, args);
		}
	}
	return (*format);
}

char *ft_get_len_modifier(char **format, t_args *sargs)
{
	if (**format == 'h')
	{
		if ((*format)[1] == 'h')
			sargs->len_modifier = hh;
		else
			sargs->len_modifier = h;
	}
	else if (**format == 'l')
	{
		if ((*format)[1] == 'l')
			sargs->len_modifier = ll;
		else
			sargs->len_modifier = l;
	}
	else if (**format == 'j' )
		sargs->len_modifier = j;
	else if (**format == 'z' )
		sargs->len_modifier = z;
	if (sargs->len_modifier == hh || sargs->len_modifier == ll)
		(*format)++;
	(*format)++;
	return (*format);
}