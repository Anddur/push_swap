/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:40:21 by mcossu            #+#    #+#             */
/*   Updated: 2021/01/12 11:40:23 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t size_src;

	size_src = 0;
	if (!dest && !src)
		return (0);
	if (size == 0)
	{
		while (src[size_src])
			size_src++;
		return (size_src);
	}
	while (size_src < size - 1 && src[size_src])
	{
		dest[size_src] = src[size_src];
		size_src++;
	}
	if (size_src < size)
		dest[size_src] = 0;
	while (src[size_src])
		size_src++;
	return (size_src);
}
