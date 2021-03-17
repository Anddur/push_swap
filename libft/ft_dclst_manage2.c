/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclst_manage2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:29:09 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/10 15:54:19 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dclst	*get_head(t_dclst *it)
{
	while (it && it->prev)
		it = it->prev;
	return (it);
}

void	*ft_dupdclst_partial(void *lst_)
{
	t_dclst *new;
	t_dclst *it;
	t_dclst *lst;

	if (!lst_)
		return (0);
	lst = lst_;
	new = ft_dclst_new(lst->c);
	lst = lst->next;
	while (lst)
	{
		if (!(it = ft_calloc(1, sizeof(t_dclst))))
		{
			ft_dclst_clear(&new);
			return (0);
		}
		it->c = lst->c;
		it->prev = new;
		new->next = it;
		new = new->next;
		lst = lst->next;
	}
	while (new && new->prev)
		new = new->prev;
	return (new);
}
