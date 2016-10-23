#include "libft.h"
#include <stdio.h>
char	*ft_wstostr(wchar_t *ws)
{
	char	*s;
	int i;

	if (!ws)
		return (NULL);
	i = 0;
	s = ft_strnew(0);
	while (ws[i])
		s = ft_strjoincl(s, ft_wctostr(ws[i++]), 3);
	return (s);
}