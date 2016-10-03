#include "libft.h"

char	*ft_strrev(char *str)
{
	char c;
	int i;
	int len;

	len = ft_strlen(str) - 1;
	i = 0;
	while (i < len)
	{
		c = str[len];
		str[len] = str[i];
		str[i] = c;
		len--;
		i++;
	}
	return (str);
}