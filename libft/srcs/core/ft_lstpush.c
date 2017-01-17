/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 01:21:41 by chbravo-          #+#    #+#             */
/*   Updated: 2016/11/18 11:53:00 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush_back(t_list **head, t_list *new)
{
	t_list	*elem;

	if (*head)
	{
		elem = *head;
		while (elem->next)
			elem = elem->next;
		elem->next = new;
	}
	else
		*head = new;
}

void	ft_lstpush_front(t_list **head, t_list *new)
{
	if (!new)
		return ;
	new->next = *head;
	*head = new;
}

t_list	*ft_lstpush(t_list **head, t_list *new, int place)
{
	t_list	*elem;
	t_list	*prev;
	int		cnt;

	if (!new)
		return (NULL);
	place = (place < 0) ? INT_MAX : place;
	elem = *head;
	prev = NULL;
	cnt = -1;
	while (++cnt < place && elem)
	{
		prev = elem;
		elem = elem->next;
	}
	new->next = elem;
	if (prev)
		prev->next = new;
	else
		*head = new;
	return (*head);
}
