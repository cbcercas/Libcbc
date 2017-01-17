/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcslen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 02:58:36 by chbravo-          #+#    #+#             */
/*   Updated: 2016/11/18 11:44:32 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "libft.h"

size_t	ft_wcslen(const wchar_t *str)
{
	const wchar_t *c;

	c = str;
	while (*c)
		c++;
	return (c - str);
}
