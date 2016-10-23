#include "libft.h"

char	*ft_ctostr(char c, int nb)
{
	char *s;

	s = ft_strnew(nb);
	ft_memset(s, c, nb);
	return (s);
}