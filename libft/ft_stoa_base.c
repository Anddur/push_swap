/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:50:54 by mcossu            #+#    #+#             */
/*   Updated: 2021/01/16 18:38:51 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			nbr_len(size_t nbr, int base)
{
	size_t len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

char		*ft_stoa_base(size_t nbr, char base_t)
{
	char	*res;
	char	*base;
	int		base_len;
	size_t	f_len;

	if (base_t == 'd')
		base = BASE_10;
	else if (base_t == 'x')
		base = BASE_16;
	base_len = ft_strlen(base);
	f_len = nbr_len(nbr, base_len);
	if (!(res = (char *)malloc(f_len + 1)))
		return (0);
	res[0] = '0';
	res[f_len] = 0;
	while (nbr)
	{
		res[--f_len] = base[nbr % base_len];
		nbr /= base_len;
	}
	return (res);
}
