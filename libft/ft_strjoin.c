/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:00:29 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/21 12:04:44 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	dim_s1;
	size_t	dim_s2;
	size_t	tot_len;

	if (!s1 && !s2)
		return (0);
	dim_s1 = ft_strlen((char *)s1);
	dim_s2 = ft_strlen((char *)s2);
	tot_len = dim_s1 + dim_s2 + 1;
	if (!(strjoin = malloc(tot_len * sizeof(char))))
		return (NULL);
	ft_memcpy(strjoin, s1, dim_s1);
	ft_memcpy(strjoin + dim_s1, s2, dim_s2);
	strjoin[tot_len - 1] = '\0';
	free((char *)s1);
	return (strjoin);
}
