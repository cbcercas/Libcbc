#include <stdarg.h>
#include "libft.h"
#include "libftprintf.h"

/*
**	sSpdDioOuUxXcC
**	%% #0-+ et espace
**	taille minimum du champ
**	la précision
**	 hh h l ll j z
*/
int		ft_print(va_list arg, const char ** restrict format)
{
	char *next_arg;

	next_arg = ft_strchr(*format, '%');
	if (!next_arg)
	{
		ft_putstr(*format);
		return (ft_strlen(*format));
	}
}

int		ft_strchrlen(char *str, char c)
{
	int i;

	i = 0;
	while (*str && *str != c)
	{
		i++;
		str++;
	}
}

char	*ft_get_format(const char ** restrict format)
{
	char	*form;
	int		formlen;
	
	formlen = ft_strchrlen(format, ' ');
	form = ft_strsub(format, 0, formlen);
	*format += formlen;
	return (form);
}



int		ft_printf(const char * restrict format, ...)
{
	int		ret;
	va_list arg;

	va_start(arg, format);
	ret = ft_print(arg, &format);
	// while(*format)
	// {
	// 	if (*format == '%')
	// 		// ft_print(format, arg)
	// }
}