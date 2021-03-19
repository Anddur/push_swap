/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stupid_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:26:54 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/19 18:48:21 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stupid_sort(t_stack *stack)
{
	int min;
	int max;

	min = find_min_stack(stack);
	max = find_max_stack(stack);
	if (stack->cont[0][0] == min)
	{
		rra(stack, 1);
		sa(stack, 1);
	}
	else if (stack->cont[2][0] == min)
	{
		if (stack->cont[0][0] == max)
		{
			sa(stack, 1);
			rra(stack, 1);
		}
		else
			rra(stack, 1);
	}
	else if (stack->cont[0][0] == max)
		ra(stack, 1);
	else
		sa(stack, 1);
}

void	choose_op(int *j, int *i, t_frame *frame)
{
	if (*j == 0)
	{
		pa(frame, 1);
		(*i)++;
		return ;
	}
	if (*j > frame->a.dim / 2)
		while (frame->a.dim - (*j)++ > 0)
			rra(&frame->a, 1);
	else
		while (*j-- > 0)
			ra(&frame->a, 1);
	pa(frame, 1);
	(*i)++;
}

void	stupid_sort_five(t_frame *frame, int *subseq)
{
	int		sub_len;

	sub_len = 0;
	enumerate_stack(&frame->a);
	subseq = calc_max_subseq(&frame->a, &sub_len);
	free(subseq);
	if (sub_len == 5)
	{
		stack_align(frame->a);
		return ;
	}
	while (frame->b.dim != 2)
	{
		if (frame->a.cont[0][0] < 3)
			pb(frame, 1);
		else
			ra(&frame->a, 1);
	}
	stupid_sort(&frame->a);
	if (frame->b.cont[0][0] == 1)
		sb(&frame->b, 1);
	pa(frame, 1);
	pa(frame, 1);
}
