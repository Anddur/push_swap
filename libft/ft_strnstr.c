/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:41:11 by mcossu            #+#    #+#             */
/*   Updated: 2021/01/12 11:41:13 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (str[i + j] && (i + j) < n)
	{
		if (to_find[j] == '\0')
			return ((char *)str + i);
		if (str[i + j] != to_find[j])
		{
			j = 0;
			i++;
		}
		else
			j++;
	}
	if ((!str[i + j] && !to_find[j]) ||
		((i + j) == n && !to_find[j]))
		return ((char *)str + i);
	return (0);
}
