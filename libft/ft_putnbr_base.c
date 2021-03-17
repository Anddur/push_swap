/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:45:04 by mcossu            #+#    #+#             */
/*   Updated: 2021/01/18 16:45:05 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_rec(size_t n, const char *base, unsigned int b_len)
{
	if (n < b_len)
	{
		ft_putchar_fd(base[n], 1);
		return ;
	}
	ft_putnbr_rec(n / b_len, base, b_len);
	ft_putchar_fd(base[(n % b_len)], 1);
	return ;
}

void		ft_putnbr_base(size_t nbr, const char *base)
{
	ft_putnbr_rec(nbr, base, (unsigned int)ft_strlen(base));
}
