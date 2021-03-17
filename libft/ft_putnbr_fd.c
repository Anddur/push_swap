/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:28:24 by mcossu            #+#    #+#             */
/*   Updated: 2021/01/12 14:28:25 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_rec(unsigned int n, int fd)
{
	if (n < 10)
	{
		ft_putchar_fd('0' + n, fd);
		return ;
	}
	ft_putnbr_rec(n / 10, fd);
	ft_putchar_fd('0' + (n % 10), fd);
	return ;
}

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int nbr;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -n;
	}
	else
		nbr = n;
	ft_putnbr_rec(nbr, fd);
}
