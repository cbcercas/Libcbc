/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:02:51 by chbravo-          #+#    #+#             */
/*   Updated: 2015/12/09 13:08:41 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (!alst)
		return ;
	if ((*alst)->next)
		ft_lstdel(&((*alst)->next), del);
	ft_lstdelone(alst, del);
}
