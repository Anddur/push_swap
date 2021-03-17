/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_manage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:31:05 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/09 18:35:58 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlst	*ft_dlst_new(void *cont)
{
	t_dlst *new;

	if (!(new = ft_calloc(1, sizeof(t_dlst))))
		return (0);
	new->cont = cont;
	return (new);
}

void	ft_dlst_insert(t_dlst **lst, t_dlst *new)
{
	t_dlst *temp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = (*lst)->next;
	(*lst)->next = new;
	new->prev = *lst;
	if (temp)
	{
		new->next = temp;
		temp->prev = new;
	}
}

void	ft_dlst_delete(t_dlst **lst)
{
	t_dlst *temp;

	if (!*lst)
		return ;
	if (!(*lst)->prev)
		return ;
	temp = (*lst)->prev;
	(*lst)->prev = temp->prev;
	if ((*lst)->prev)
		(*lst)->prev->next = *lst;
	free(temp);
}

void	ft_dlst_clear(t_dlst **lst, void (*clear)(void *))
{
	t_dlst *temp;

	if (!*lst)
		return ;
	while ((*lst) && (*lst)->prev)
		*lst = (*lst)->prev;
	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		clear(&temp->cont);
		free(temp);
	}
	*lst = 0;
}

t_dlst	*ft_dupdlst(t_dlst *lst, void *(*dup)(void *), void (*clear)(void *))
{
	t_dlst *new;
	t_dlst *it;
	t_dlst *temp;

	if (!lst || !(new = ft_calloc(1, sizeof(t_dlst))))
		return (0);
	if (!(new->cont = dup(lst->cont)))
	{
		free(new);
		return (0);
	}
	it = new;
	lst = lst->next;
	while (lst)
	{
		if (!(temp = ft_dlst_new(dup(lst->cont))))
		{
			ft_dlst_clear(&new, clear);
			return (0);
		}
		ft_dlst_insert(&it, temp);
		it = it->next;
		lst = lst->next;
	}
	return (new);
}
