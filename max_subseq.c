/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_subseq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:58:48 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/17 12:43:33 by aduregon         ###   ########.fr       */
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
		puts("vvv");
		if (min > arr[i])
			min = arr[i];
		i++;
	}
	return (min);
}

void	take_min(int **copy, int len)
{
	int		min;

	min = find_min(*copy, len);
	printf("min %d\n", min);
}

void	calc_max_subseq(t_stack *stack)
{
	int		*copy;

	copy = copy_stack(stack);
	take_min(&copy, stack->dim);
}