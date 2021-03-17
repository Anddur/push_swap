/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrm_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:21:36 by mcossu            #+#    #+#             */
/*   Updated: 2021/02/24 14:45:29 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrm_if(t_lst **head, void *data, int (*cmp)(void *, void *),
			void (*del)(void *))
{
	t_lst *it;
	t_lst *temp;

	it = *head;
	while (it && !cmp(data, it->cont))
	{
		*head = it->next;
		ft_lstdelone(it, del);
		it = *head;
	}
	if (!it)
		return ;
	while (it->next)
	{
		if (!cmp(data, it->next->cont))
		{
			temp = it->next;
			it->next = temp->next;
			ft_lstdelone(temp, del);
		}
		else
			it = it->next;
	}
}
