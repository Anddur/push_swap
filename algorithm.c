/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:40:04 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/18 18:33:26 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_min_pos(t_stack stack)
{
	int min;
	int i;
	int pos;

	i = 0;
	min = stack.cont[i][0];
	pos = i;
	while (i < stack.dim)
	{
		if (min > stack.cont[i][0])
		{
			min = stack.cont[i][0];
			pos = i;
		}
		i++;
	}
	return (pos);
}

void	stack_align(t_stack stack)
{
	int tmp;
	int min_pos;
	int i;

	i = 0;
	min_pos = find_min_pos(stack);
	tmp = stack.dim - min_pos;
	if (min_pos > tmp)
	{
		while (i++ <= tmp)
			rra(&stack, 1);
	}
	else
	{
		while (i++ < min_pos)
			ra(&stack, 1);
	}
}

void	solve(t_frame *frame, int *subseq, int sub_len, int stack_len)
{
	divide_stack(frame, subseq, sub_len);
	while (frame->b.dim)
		merge_stack(frame);
	stack_align(frame->a);
	stack_len = 0;
}
