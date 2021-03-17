/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:44:12 by mcossu            #+#    #+#             */
/*   Updated: 2021/01/12 11:44:13 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	res_len;
	char	*res;

	if (!s1 || !s2)
		return (0);
	res_len = ft_strlen(s1) + ft_strlen(s2);
	if (!(res = (char *)malloc((res_len + 1) * sizeof(char))))
		return (0);
	while (*s1)
		*res++ = *s1++;
	while (*s2)
		*res++ = *s2++;
	*res = 0;
	return (res - res_len);
}
