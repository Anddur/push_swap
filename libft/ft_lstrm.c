/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 11:51:56 by mcossu            #+#    #+#             */
/*   Updated: 2021/02/18 11:51:57 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lstrm(t_lst **lst, char (*f)(void *, int, int), int x, int y)
{
	t_lst *it;
	t_lst *temp;

	it = *lst;
	if (!it || !f)
		return (0);
	if (f((*lst)->cont, x, y))
	{
		temp = *lst;
		*lst = (*lst)->next;
		temp->next = 0;
		return (temp);
	}
	while (it->next)
	{
		if (f(it->next->cont, x, y))
		{
			temp = it->next;
			it->next = it->next->next;
			temp->next = 0;
			return (temp);
		}
		it = it->next;
	}
	return (0);
}
