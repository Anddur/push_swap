/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:43:00 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/19 12:20:29 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_max_pos(int **a, int dim)
{
	int pos;
	int max;
	int i;

	max = a[0][0];
	i = 0;
	pos = i;
	while (i < dim)
	{
		if (a[i][0] > max)
		{
			max = a[i][0];
			pos = i;
		}
		i++;
	}
	return (pos);
}

int		find_place(int **a, int b, int dim)
{
	int i;
	int max_pos;

	i = 0;
	max_pos = 0;
	while (i < dim)
	{
		if (i == 0)
			if (b < a[i][0] && b > a[dim - 1][0])
				return (i);
		if (b > a[i][0] && b < a[i + 1][0])
		{
			if (i > dim / 2)
				return (i - (dim) + 1);
			else
				return (i + 1);
		}
		i++;
	}
	max_pos = find_max_pos(a, dim) + 1;
	if (max_pos == dim)
		max_pos = 0;
	if (max_pos > dim - max_pos)
		max_pos = -(dim - max_pos);
	return (max_pos);
}

void	find_best(t_frame *frame, int *a, int *b)
{
	int i;
	int tmp[2];

	i = 0;
	*a = -(frame->a.dim);
	*b = frame->b.dim;
	while (i < frame->b.dim)
	{
		if (count_op(i, 0) >= count_op(*a, *b))
			break ;
		tmp[0] = find_place(frame->a.cont, frame->b.cont[i][0], frame->a.dim);
		tmp[1] = i;
		compare_op(tmp[0], tmp[1], a, b);
		tmp[0] = find_place(frame->a.cont,
				frame->b.cont[(frame->b.dim - i) %
				frame->b.dim][0], frame->a.dim);
		tmp[1] = -i;
		compare_op(tmp[0], tmp[1], a, b);
		i++;
	}
}

void	multi_op(t_frame *frame, int *a, int *b)
{
	int		i;
	int		tmp;

	i = 0;
	if ((*a * *b) > 0)
	{
		tmp = *a > 0 ? MIN(*a, *b) : MAX(*a, *b);
		if (*a > 0)
			while (i++ < ABS(tmp))
			{
				rr(frame, 1);
				(*a)--;
				(*b)--;
			}
		else
			while (i++ < ABS(tmp))
			{
				rrr(frame, 1);
				(*a)++;
				(*b)++;
			}
	}
}

void	merge_stack(t_frame *frame)
{
	int		op[2];
	int		i;

	i = 0;
	find_best(frame, &op[0], &op[1]);
	multi_op(frame, &op[0], &op[1]);
	if (op[0] > 0)
		while (i++ < op[0])
			ra(&frame->a, 1);
	else
		while (i++ < ABS(op[0]))
			rra(&frame->a, 1);
	i = 0;
	if (op[1] > 0)
		while (i++ < op[1])
			rb(&frame->b, 1);
	else
		while (i++ < ABS(op[1]))
			rrb(&frame->b, 1);
	pa(frame, 1);
}
