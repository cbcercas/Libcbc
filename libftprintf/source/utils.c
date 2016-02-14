#include "libft.h"

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