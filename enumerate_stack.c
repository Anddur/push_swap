/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enumerate_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:55:59 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/19 12:16:07 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		merge(int *copy_arr, int l, int m, int r)
{
	int i;
	int j;
	int k;
	int b[r - l];

	i = l;
	j = m + 1;
	k = 0;
	while (i <= m && j <= r)
		b[k++] = (copy_arr[i] < copy_arr[j]) ?
			copy_arr[i++] : copy_arr[j++];
	while (i <= m)
		b[k++] = copy_arr[i++];
	while (j <= r)
		b[k++] = copy_arr[j++];
	k = l;
	while (k <= r)
	{
		copy_arr[k] = b[k - l];
		k++;
	}
}

void		merge_sort(int *copy_arr, int l, int r)
{
	int		m;

	if (l < r)
	{
		m = (l + r) / 2;
		merge_sort(copy_arr, l, m);
		merge_sort(copy_arr, m + 1, r);
		merge(copy_arr, l, m, r);
	}
}

void		enumerate_stack(t_stack *stack)
{
	int		*copy_arr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	copy_arr = copy_stack(stack);
	merge_sort(copy_arr, 0, stack->dim - 1);
	while (i < stack->dim)
	{
		j = 0;
		while (j < stack->dim)
		{
			if (copy_arr[i] == stack->cont[j][0])
				stack->cont[j][1] = i + 1;
			j++;
		}
		i++;
	}
	free(copy_arr);
}
