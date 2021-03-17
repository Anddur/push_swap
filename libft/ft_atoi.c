/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:41:34 by mcossu            #+#    #+#             */
/*   Updated: 2021/01/12 11:41:35 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

int		ft_atoi(const char *str)
{
	int				minus;
	unsigned int	result;

	minus = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	if (!is_numeric(*str))
		return (-1);
	while (is_numeric(*str) && result <= 2147483647)
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	if ((result == 2147483648 && minus == -1)
		|| result <= 2147483647)
		return (minus * result);
	return (minus == 1 ? -1 : 0);
}
