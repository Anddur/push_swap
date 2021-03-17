/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:41:00 by mcossu            #+#    #+#             */
/*   Updated: 2021/01/12 11:41:02 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *new;

	new = 0;
	while (*s)
	{
		if (*s == (char)c)
			new = (char *)s;
		s++;
	}
	if ((char)c == 0)
		return ((char *)s);
	return (new);
}
