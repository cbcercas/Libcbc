/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstostr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 02:58:36 by chbravo-          #+#    #+#             */
/*   Updated: 2016/11/18 11:40:45 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_wstostr(wchar_t *ws)
{
	char	*s;
	int		i;

	if (!ws)
		return (NULL);
	i = 0;
	s = ft_strnew(0);
	while (ws[i])
		s = ft_strjoincl(s, ft_wctostr(ws[i++]), 3);
	return (s);
}
