#include <stdarg.h>
#include "libft.h"
#include "type.h"

char	*ft_get_flags(char **format, t_args	*sarg)
{
	if (**format == '#' || **format == '0' || **format == '-'
		|| **format == ' ' || **format == '+' || **format == 103)
	{
		
		if (**format == '#')
			sarg->alternate = 1;
		else if (**format == '0')
			sarg->zero_pad = 1;
		else if (**format == '-')
			sarg->left_pad = 1;
		else if (**format == ' ' && !sarg->sign_pos)
			sarg->blank_pos = 1;
		else if (**format == '+')
		{
			sarg->sign_pos = 1;
			sarg->blank_pos = 0;
		}
		else if (**format == 103)
			sarg->deci_conv = 1;
		(*format)++;
		return(ft_get_flags(format, sarg));
	}
	return(*format);
}

char *ft_get_width(char **format, t_args *sarg, va_list *larg)
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
			sarg->min_width = va_arg(larg, int);
			(*format)++;
		}
	}
	return (*format);
}

char *ft_get_precision(char **format, t_args *sarg, va_list *larg)
{
	if (**format == '.' || ft_isdigit(**format))
	{
		if (ft_isdigit(**format))
		{
			sarg->precision = ((sarg->precision) * 10) + ((**format) - '0');
			(*format)++;
			(*format) = ft_get_precision(format, sarg, larg);
		}
		else
		{
			(*format)++;
			sarg->precision = 0;
			(*format) = ft_get_precision(format, sarg, larg);
		}
	}
	return (*format);
}

char *ft_get_len_modifier(char **format, t_args *sarg)
{
	if (**format == 'h')
	{
		if (*(*format + 1) == 'h')
			sarg->len_modifier = hh;
		else
			sarg->len_modifier = h;
	}
	else if (**format == 'l')
	{
		if (*(*format + 1) == 'l')
			sarg->len_modifier = ll;
		else
			sarg->len_modifier = l;
	}
	else if (**format == 'j' )
		sarg->len_modifier = j;
	else if (**format == 'z' )
		sarg->len_modifier = z;
	else
		return (*format);
	if (sarg->len_modifier == hh || sarg->len_modifier == ll)
		(*format)++;
	if (sarg->len_modifier > 0)
		(*format)++;
	return (*format);
}

static char *ft_get_conversion2(char **format, t_args *sarg)
{
	if (**format == 'X')
		sarg->conversion = X;
	else if (**format == 'c')
		sarg->conversion = c;
	else if (**format == 'C')
		sarg->conversion = C;
	else
		return (NULL);
	(*format)++;
	return (*format);
}

char *ft_get_conversion(char **format, t_args *sarg)
{
	//ft_putchar(*format);
	if (**format == 's')
		sarg->conversion = s;
	else if (**format == 'S')
		sarg->conversion = S;
	else if (**format == 'p')
		sarg->conversion = p;
	else if (**format == 'd')
		sarg->conversion = d;
	else if (**format == 'D')
		sarg->conversion = D;
	else if (**format == 'i')
		sarg->conversion = i;
	else if (**format == 'o')
		sarg->conversion = o;
	else if (**format == 'O')
		sarg->conversion = O;
	else if (**format == 'u')
		sarg->conversion = u;
	else if (**format == 'U')
		sarg->conversion = U;
	else if (**format == 'x')
		sarg->conversion = x;
	else 
		return (ft_get_conversion2(format, sarg));
	(*format)++;
	return (*format);
}
