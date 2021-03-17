/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:44:23 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/02 18:12:49 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char const *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char		*res;
	char const	*begin;
	size_t		j;
	size_t		i;

	i = 0;
	if (!s1 || !set)
		return (0);
	while (s1[i] && ft_isset(s1[i], set))
		i++;
	begin = (s1 + i);
	j = ft_strlen(s1);
	if (i >= j || !*s1)
	{
		if (!(res = (char *)malloc((1) * sizeof(char))))
			return (0);
		*res = 0;
		return (res);
	}
	while ((s1 + j) != begin && ft_isset(*(s1 + j), set))
		j--;
	if (!(res = (char *)malloc((j - i + 2) * sizeof(char))))
		return (0);
	ft_strlcpy(res, begin, j - i + 2);
	return (res);
}
