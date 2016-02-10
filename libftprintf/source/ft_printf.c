#include <stdlib.h>
#include "libft.h"
#include "libftprintf.h"
#include <stdio.h>

/*
**	sSpdDioOuUxXcC
**	%% #0-+ et espace
**	taille minimum du champ
**	la précision
**	 hh h l ll j z
*/

/*
** TMP: test args parsing
*/
void ft_aff_args(t_args	*sargs)
{
	printf("alternate: %u,\n", sargs->alternate);
	printf("zero_pad: %u,\n", sargs->zero_pad);
	printf("left_pad: %u,\n", sargs->left_pad);
	printf("blank_pos: %u,\n", sargs->blank_pos);
	printf("sign_pos: %u,\n", sargs->sign_pos);
	printf("deci_conv: %u,\n", sargs->deci_conv);
	printf("min_width: %u,\n", sargs->min_width);
	printf("precision: %u\n", sargs->precision);
	printf("len_modifier: %u\n", sargs->len_modifier);
}

t_args	*ft_get_args(char **format, va_list *args)
{
	t_args	*sargs;

	sargs = malloc(sizeof(t_args));
	if (!sargs)
		return (NULL);
	if (*++*format == '\0')
		return (NULL);
	(*format) = ft_get_flags(format, sargs);
	(*format) = ft_get_width(format, sargs, args);
	(*format) = ft_get_precision(format, sargs, args);
	(*format) = ft_get_len_modifier(format, sargs);
	return (sargs);
}

int		ft_print(va_list *args, const char *format, int printed)
{
	char	*next_arg;
	t_args	*sargs;

	next_arg = ft_strchr(format, '%');
	if (!next_arg)
	{
		ft_putstr(format);
		return (printed + ft_strlen(format));
	}
	else if (next_arg > format)
	{
		ft_putnstr(format, next_arg - format);
		return(ft_print(args, next_arg, printed + (next_arg - format)));
	}
	else
	{
		sargs = ft_get_args(&(next_arg), args);
		if (!sargs)
			return (-1);
		ft_aff_args(sargs);
		return (printed); // + ft_print_arg(arg, &next_arg)
	}
}

// int		ft_strchrlen(const char *str, char c)
// {
// 	int i;

// 	i = 0;
// 	while (*str && *str != c)
// 	{
// 		i++;
// 		str++;
// 	}
// 	return (i);
// }

// char	*ft_get_format(const char * restrict format)
// {
// 	char	*form;
// 	int		formlen;
	
// 	formlen = ft_strchrlen(format, ' ');
// 	form = ft_strsub(format, 0, formlen);
// 	format += formlen;
// 	return (form);
// }



int		ft_printf(const char * restrict format, ...)
{
	int		ret;
	va_list args;

	va_start(args, format);
	ret = ft_print(&args, format, 0);
	return (ret);
	// while(*format)
	// {
	// 	if (*format == '%')
	// 		// ft_print(format, arg)
	// }
}