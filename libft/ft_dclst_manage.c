/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclst_manage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:31:05 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/09 18:47:22 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dclst	*ft_dclst_new(char c)
{
	t_dclst *new;

	if (!(new = ft_calloc(1, sizeof(t_dclst))))
		return (0);
	new->c = c;
	return (new);
}

void	ft_dclst_insert(t_dclst **lst, t_dclst *new)
{
	t_dclst *temp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (!(*lst)->prev)
	{
		temp = *lst;
		*lst = new;
		new->next = temp;
		temp->prev = new;
		*lst = (*lst)->next;
		return ;
	}
	temp = (*lst);
	temp->prev->next = new;
	new->next = temp;
	new->prev = temp->prev;
	temp->prev = new;
}

void	ft_dclst_delete(t_dclst **lst)
{
	t_dclst *temp;

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

void	ft_dclst_clear(void *lst_)
{
	t_dclst *temp;
	t_dclst **lst;
	t_dclst *it;

	lst = lst_;
	if (!*lst)
		return ;
	it = *lst;
	while (it && it->prev)
		it = it->prev;
	while (it)
	{
		temp = it;
		it = it->next;
		free(temp);
	}
	*lst = 0;
}

void	*ft_dupdclst(void *lst_)
{
	t_dclst *new;
	t_dclst *it;
	t_dclst *lst;

	if (!lst_)
		return (0);
	lst = get_head(lst_);
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
