#include "libft.h"
# include "type.h"

int ft_print_pad(int len_res, int pad, char c)
{
	int i;

	i = 0;
	while (pad > len_res)
	{
		ft_putchar(c);
		pad--;
		i++;
	}
	return (i);
}

intmax_t ft_signed_from_lenght(t_args *sarg, intmax_t nb)
{
	if (sarg->len_modifier == h)
		return ((short)nb);
	else if (sarg->len_modifier == l)
		return ((long)nb);
	else if (sarg->len_modifier == ll)
		return ((long long)nb);
	else if (sarg->len_modifier == j)
		return (nb);
	else if (sarg->len_modifier == z)
		return ((size_t)nb);
	else
		return ((int)nb);
}

intmax_t ft_unsigned_from_lenght(t_args *sarg, uintmax_t nb)
{
	if (sarg->len_modifier == h)
		return ((unsigned short)nb);
	else if (sarg->len_modifier == l)
		return ((unsigned long)nb);
	else if (sarg->len_modifier == ll)
		return ((unsigned long long)nb);
	else if (sarg->len_modifier == j)
		return (nb);
	else if (sarg->len_modifier == z)
		return ((size_t)nb);
	else
		return ((unsigned int)nb);
}