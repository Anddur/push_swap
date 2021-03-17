/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 13:32:58 by mcossu            #+#    #+#             */
/*   Updated: 2021/01/12 13:33:01 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_number_len(int n)
{
	unsigned int	nbr;
	int				len;

	len = 0;
	if (n < 0)
	{
		len++;
		nbr = -n;
	}
	else
		nbr = n;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static void	ft_rec_itoa(char **ptr, unsigned int nbr)
{
	if (nbr < 10)
	{
		**ptr = '0' + nbr;
		(*ptr)++;
		**ptr = 0;
		return ;
	}
	ft_rec_itoa(ptr, nbr / 10);
	**ptr = (nbr % 10) + '0';
	(*ptr)++;
	return ;
}

char		*ft_itoa(int n)
{
	char			*res;
	char			*begin;
	int				n_len;
	unsigned int	nbr;

	n_len = ft_number_len(n);
	if (!(res = malloc((n_len + 1) * sizeof(char))))
		return (0);
	begin = res;
	if (n < 0)
	{
		*res = '-';
		res++;
		nbr = -n;
	}
	else
		nbr = n;
	ft_rec_itoa(&res, nbr);
	*res = 0;
	return (begin);
}
