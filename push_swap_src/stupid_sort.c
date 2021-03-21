/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stupid_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:26:54 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/21 10:18:24 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_order(t_stack stack)
{
	int i;

	i = 0;
	while (i < stack.dim - 1)
	{
		if (stack.cont[i][0] > stack.cont[i + 1][0])
			return (0);
		i++;
	}
	return (1);
}

void	stupid_sort(t_frame *frame, int vis)
{
	int val[2];

	if (is_order(frame->a))
		return ;
	val[0] = find_min_stack(&frame->a);
	val[1] = find_max_stack(&frame->a);
	if (frame->a.cont[0][0] == val[0])
	{
		rra(frame, vis);
		sa(frame, vis);
	}
	else if (frame->a.cont[2][0] == val[0])
	{
		if (frame->a.cont[0][0] == val[1])
		{
			sa(frame, vis);
			rra(frame, vis);
		}
		else
			rra(frame, 1);
	}
	else if (frame->a.cont[0][0] == val[1])
		ra(frame, vis);
	else
		sa(frame, vis);
}

void	choose_op(int *j, int *i, t_frame *frame, int vis)
{
	if (*j == 0)
	{
		pa(frame, vis);
		(*i)++;
		return ;
	}
	if (*j > frame->a.dim / 2)
		while (frame->a.dim - (*j)++ > 0)
			rra(frame, vis);
	else
		while (*j-- > 0)
			ra(frame, vis);
	pa(frame, vis);
	(*i)++;
}

void	stupid_sort_five(t_frame *frame, int *subseq, int vis)
{
	int		sub_len;

	sub_len = 0;
	enumerate_stack(&frame->a);
	subseq = calc_max_subseq(&frame->a, &sub_len);
	free(subseq);
	if (sub_len == 5)
	{
		stack_align(frame, vis);
		return ;
	}
	while (frame->b.dim != 2)
	{
		if (frame->a.cont[0][1] < 3)
			pb(frame, vis);
		else
			ra(frame, vis);
	}
	stupid_sort(frame, vis);
	if (frame->b.cont[0][1] == 1)
		sb(frame, vis);
	pa(frame, vis);
	pa(frame, vis);
}
