/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 12:35:55 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/21 12:36:38 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atoi_long(const char *str)
{
	size_t				index;
	int					neg;
	unsigned long int	res;

	index = 0;
	neg = 1;
	res = 0;
	while (ft_isspace(str[index]))
		index++;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			neg = -1;
		index++;
	}
	while (ft_isdigit(str[index]))
	{
		res *= 10;
		res += str[index] - 48;
		index++;
	}
	return (res * neg);
}