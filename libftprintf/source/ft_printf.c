#include <stdlib.h>
#include "libft.h"
#include "libftprintf.h"
#include "printf.h"
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
void ft_aff_args(t_args	*sarg)
{
	printf("alternate: %u,\n", sarg->alternate);
	printf("zero_pad: %u,\n", sarg->zero_pad);
	printf("left_pad: %u,\n", sarg->left_pad);
	printf("blank_pos: %u,\n", sarg->blank_pos);
	printf("sign_pos: %u,\n", sarg->sign_pos);
	printf("deci_conv: %u,\n", sarg->deci_conv);
	printf("min_width: %u,\n", sarg->min_width);
	printf("precision: %u\n", sarg->precision);
	printf("len_modifier: %u\n", sarg->len_modifier);
	printf("conversion: %u\n", sarg->conversion);
}

int ft_get_args(char **format, va_list *larg, t_args *sarg)
{
	char *save;

	if (*++*format == '\0')
		return (1);
	save = (*format);
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
	// if (*format == save)
	//  	return (2);
	return (0);
}

int		ft_print_args(t_args *sarg, va_list *larg)
{
	// int i;
	// va_list larg2;

	// i = 0;
	// va_copy(larg2, *larg);
	// while (i <= va_arg(larg2, int))
	// 	i++;
	// va_end(larg2);
	// if (i > 0)
	if ((sarg->conversion >= c) && (sarg->conversion <= per))
		return (print[(sarg->conversion - 1)](sarg, larg));	
	else
		return (0);
}

int		ft_print(va_list *larg, const char *format, int printed)
{
	char	*next_arg;
	t_args	sarg;
	int		ret;

	next_arg = ft_strchr(format, '%');
	if (!next_arg)
	{
		ft_putstr(format);
		//printf("strlen %s: %lu\n",format, ft_strlen(format));
		return (printed + ft_strlen(format));
	}
	else if (next_arg > format)
	{
		ft_putnstr(format, next_arg - format);
		return(ft_print(larg, next_arg, printed + (next_arg - format)));
	}
	else
	{
		ft_bzero(&sarg, sizeof(sarg)); //malloc?
		ret = ft_get_args(&(next_arg), larg, &sarg);
		// ft_aff_args(&sarg);
		// printf("\nret = %d\n", ret);
		if (ret == 1)
			return (0);
		else if (ret == -1)
			return (-1);
		// printf("non\n");
		ret = ft_print_args(&sarg, larg);
		if (ret == -1)
			return (-1);
		ret = ft_print(larg, next_arg, printed + ret);
		if (ret == -1)
			return (-1);
		return (ret); // + ft_print_arg(arg, &next_arg)
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
	va_list larg;

	va_start(larg, format);
	ret = ft_print(&larg, format, 0);
	return (ret);
	// while(*format)
	// {
	// 	if (*format == '%')
	// 		// ft_print(format, arg)
	// }
}