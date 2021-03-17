/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:44:00 by mcossu            #+#    #+#             */
/*   Updated: 2021/01/12 11:44:02 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	size_t			final_len;
	char			*res;

	if (!s)
		return (0);
	i = ft_strlen(s);
	if (start >= i)
	{
		if (!(res = (char *)malloc((1) * sizeof(char))))
			return (0);
		*res = 0;
		return (res);
	}
	final_len = (i - start) > len ? len : i - start;
	if (!(res = (char *)malloc((final_len + 1) * sizeof(char))))
		return (0);
	i = start;
	while (s[i] && (i - start) < len)
	{
		res[i - start] = s[i];
		i++;
	}
	res[i - start] = 0;
	return (res);
}
