/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 12:09:08 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/13 12:09:10 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_lst **lst, void (*del)(void*))
{
	t_lst *temp;
	t_lst *iter;

	if (!lst)
		return ;
	iter = *lst;
	while (iter)
	{
		temp = iter->next;
		ft_lstdelone(iter, del);
		iter = temp;
	}
	*lst = 0;
}
