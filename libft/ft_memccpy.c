/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:39:17 by mcossu            #+#    #+#             */
/*   Updated: 2021/01/12 11:39:20 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(dest + i) = *(const unsigned char *)(src + i);
		if (*(const unsigned char *)(src + i) == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (0);
}
