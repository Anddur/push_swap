/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 08:24:46 by mcossu            #+#    #+#             */
/*   Updated: 2021/02/23 15:42:47 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lstfind(t_lst *lst, void *data, int (*f)(void *, void *))
{
	t_lst *it;

	it = lst;
	if (!lst)
		return (0);
	while (it)
	{
		if (!f(data, it->cont))
			return (it);
		it = it->next;
	}
	return (it);
}
