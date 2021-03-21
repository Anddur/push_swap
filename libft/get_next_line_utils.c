/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 09:15:37 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/21 12:09:25 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_blst	*new_node(int fd)
{
	t_blst	*iter;

	if (!(iter = (t_blst *)malloc(sizeof(t_blst))))
		return (0);
	iter->fd = fd;
	iter->buff[0] = 0;
	iter->next = 0;
	return (iter);
}

void	delete_node(t_blst **head, t_blst *to_del)
{
	t_blst *iter;

	iter = *head;
	if (*head == to_del)
	{
		*head = (*head)->next;
		free(iter);
		return ;
	}
	while (iter && iter->next != to_del)
		iter = iter->next;
	iter->next = to_del->next;
	free(to_del);
}

t_blst	*find_fd(t_blst **head, int fd)
{
	t_blst	*iter;

	iter = *head;
	if (!*head)
	{
		if (!(*head = new_node(fd)))
			return (0);
		return (*head);
	}
	if ((*head)->fd == fd)
		return (*head);
	while (iter->next)
	{
		if (iter->next->fd == fd)
			return (iter->next);
		iter = iter->next;
	}
	if (!(iter->next = new_node(fd)))
		return (0);
	return (iter->next);
}
