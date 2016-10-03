#include "libft.h"

char	*ft_uitooctal(uintmax_t nb, int prefix)
{
	char *nbbase;
	char *ret;
	int i;

	nbbase = ft_uitobase(nb, 8);
	if (!prefix)
		return (nbbase);
	ret = ft_strnew(2 + ft_strlen(nbbase));
	ret[0] = '0';
	i = 0;
	while (nbbase[i] != '\0')
	{
		ret[i + 1] = nbbase[i];
		i++;
	}
	free(nbbase);
	return (ret);
}
