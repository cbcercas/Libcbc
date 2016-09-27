/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 11:51:27 by chbravo-          #+#    #+#             */
/*   Updated: 2015/12/09 11:58:07 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordlen(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}
