/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:02:51 by chbravo-          #+#    #+#             */
/*   Updated: 2015/12/09 13:05:17 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	*get_call_error(void)
{
	static size_t	call_error = 0;

	return (&call_error);
}

static	BOOL is_error_malloc(void)
{
	static size_t	call = 0;
	size_t			*call_error;

	call_error = get_call_error();
	if (!*call_error)
		return (false);
	if (call++ >= *call_error)
		return (true);
	return (false);
}

void	ft_memalloc_test_init(size_t nb_call)
{
	*get_call_error() = nb_call;
}

void	*ft_memalloc(size_t size)
{
	char *mem;

	if (!size || is_error_malloc())
		return (NULL);
	mem = (char *)malloc(size);
	if (!mem)
		return (0);
	ft_bzero(mem, size);
	return ((char *)mem);
}
