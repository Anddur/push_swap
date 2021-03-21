/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:40:04 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/21 10:40:38 by aduregon         ###   ########.fr       */
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

void	stack_align(t_frame *frame, int vis)
{
	int tmp;
	int min_pos;
	int i;

	i = 0;
	min_pos = find_min_pos(frame->a);
	tmp = frame->a.dim - min_pos;
	if (min_pos > tmp)
	{
		while (i++ < tmp)
			rra(frame, vis);
	}
	else
	{
		while (i++ < min_pos)
			ra(frame, vis);
	}
}

void	solve(t_frame *frame, int stack_len, int vis)
{
	divide_stack(frame, frame->subseq, frame->sub_len, vis);
	while (frame->b.dim)
		merge_stack(frame, vis);
	stack_align(frame, vis);
	stack_len = 0;
}
