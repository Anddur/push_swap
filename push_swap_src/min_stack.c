/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 12:17:37 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/19 17:31:04 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_min(int *arr, int len)
{
	int min;
	int i;

	i = 0;
	min = arr[i];
	while (i < len)
	{
		if (min > arr[i])
			min = arr[i];
		i++;
	}
	return (min);
}

void	*ft_memmove_int(void *dest, const void *src, size_t n)
{
	int			*tmp;
	const int	*s;

	if (!dest && !src)
		return (0);
	if (dest <= src)
	{
		tmp = dest;
		s = src;
		while (n--)
			*tmp++ = *s++;
	}
	else
	{
		tmp = dest;
		tmp += n;
		s = src;
		s += n;
		while (n--)
			*--tmp = *--s;
	}
	return (dest);
}

int		find_min_stack(t_stack *stack)
{
	int min;
	int i;
	int pos;

	i = 0;
	min = stack->cont[i][0];
	pos = i;
	while (i < stack->dim)
	{
		if (min > stack->cont[i][0])
			min = stack->cont[i][0];
		i++;
	}
	return (min);
}

int		find_max_stack(t_stack *stack)
{
	int max;
	int i;
	int pos;

	i = 0;
	max = stack->cont[i][0];
	pos = i;
	while (i < stack->dim)
	{
		if (max < stack->cont[i][0])
			max = stack->cont[i][0];
		i++;
	}
	return (max);
}
