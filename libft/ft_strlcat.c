/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:40:36 by mcossu            #+#    #+#             */
/*   Updated: 2021/01/12 11:40:37 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	char		*dest;
	char const	*s;
	size_t		n;
	size_t		dlen;

	dest = dst;
	s = src;
	n = size;
	while (n-- && *dest)
		dest++;
	dlen = dest - dst;
	n = size - dlen;
	if (n == 0)
		return (size + ft_strlen(s));
	while (s && *s)
	{
		if (n != 1)
		{
			*dest++ = *s;
			n--;
		}
		s++;
	}
	*dest = '\0';
	return (dlen + (s - src));
}
