/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_sorted.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 12:08:59 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/13 12:09:00 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_sorted(t_lst **head, t_lst *new,
						int (*cmp)(void *, void *))
{
	t_lst	*it;
	void	*temp;

	if (!head)
		return ;
	it = *head;
	*head = new;
	new->next = it;
	it = new;
	while (it->next)
	{
		if (cmp(it->cont, it->next->cont) > 0)
		{
			temp = it->cont;
			it->cont = it->next->cont;
			it->next->cont = temp;
			it = it->next;
		}
		else
			return ;
	}
}
