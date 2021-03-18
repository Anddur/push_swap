/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:20:07 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/18 11:22:38 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack *stack, int v)
{
	int value;
	int index;

	if (stack->dim < 2)
		return ;
	value = stack->cont[0][0];
	index = stack->cont[0][1];
	stack->cont[0][0] = stack->cont[1][0];
	stack->cont[0][1] = stack->cont[1][1];
	stack->cont[1][0] = value;
	stack->cont[1][1] = index;
	if (v)
		write(1, "sb\n", 3);
}

void	rb(t_stack *stack, int v)
{
	int value;
	int index;
	int i;

	if (stack->dim < 2)
		return ;
	i = 0;
	value = stack->cont[0][0];
	index = stack->cont[0][1];
	while (i < stack->dim - 1)
	{
		stack->cont[i][0] = stack->cont[i + 1][0];
		stack->cont[i][1] = stack->cont[i + 1][1];
		i++;
	}
	stack->cont[i][0] = value;
	stack->cont[i][1] = index;
	if (v)
		write(1, "rb\n", 3);
}

void	rrb(t_stack *stack, int v)
{
	int value;
	int index;
	int i;

	if (stack->dim < 2)
		return ;
	i = stack->dim - 1;
	value = stack->cont[stack->dim - 1][0];
	index = stack->cont[stack->dim - 1][1];
	while (i > 0)
	{
		stack->cont[i][0] = stack->cont[i - 1][0];
		stack->cont[i][1] = stack->cont[i - 1][1];
		i--;
	}
	stack->cont[i][0] = value;
	stack->cont[i][1] = index;
	if (v)
		write(1, "rrb\n", 4);
}

void	swap_b(t_stack *stack)
{
	int i;

	i = stack->dim - 1;
	while (i > 0)
	{
		stack->cont[i][0] = stack->cont[i - 1][0];
		stack->cont[i][1] = stack->cont[i - 1][1];
		i--;
	}
}

void	pb(t_frame *frame, int v)
{
	int value;
	int index;
	int i;

	if (frame->a.dim == 0)
		return ;
	value = frame->a.cont[0][0];
	index = frame->a.cont[0][1];
	i = 0;
	while (i < frame->a.dim - 1)
	{
		frame->a.cont[i][0] = frame->a.cont[i + 1][0];
		frame->a.cont[i][1] = frame->a.cont[i + 1][1];
		i++;
	}
	frame->a.dim--;
	frame->b.dim++;
	swap_b(&frame->b);
	frame->b.cont[0][0] = value;
	frame->b.cont[0][1] = index;
	if (v)
		write(1, "pb\n", 3);
}
