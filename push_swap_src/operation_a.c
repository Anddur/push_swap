/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:21:15 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/21 11:47:58 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_frame *frame, int v)
{
	int value;
	int index;

	if (frame->a.dim < 2)
		return ;
	value = frame->a.cont[0][0];
	index = frame->a.cont[0][1];
	frame->a.cont[0][0] = frame->a.cont[1][0];
	frame->a.cont[0][1] = frame->a.cont[1][1];
	frame->a.cont[1][0] = value;
	frame->a.cont[1][1] = index;
	if (v)
		write(1, "sa\n", 3);
	else
		print_stack(*frame);
}

void	ra(t_frame *frame, int v)
{
	int value;
	int index;
	int i;

	if (frame->a.dim < 2)
		return ;
	i = 0;
	value = frame->a.cont[0][0];
	index = frame->a.cont[0][1];
	while (i < frame->a.dim - 1)
	{
		frame->a.cont[i][0] = frame->a.cont[i + 1][0];
		frame->a.cont[i][1] = frame->a.cont[i + 1][1];
		i++;
	}
	frame->a.cont[i][0] = value;
	frame->a.cont[i][1] = index;
	if (v == 1)
		write(1, "ra\n", 3);
	else if (v == 0)
		print_stack(*frame);
}

void	rra(t_frame *frame, int v)
{
	int value;
	int index;
	int i;

	if (frame->a.dim < 2)
		return ;
	i = frame->a.dim - 1;
	value = frame->a.cont[frame->a.dim - 1][0];
	index = frame->a.cont[frame->a.dim - 1][1];
	while (i > 0)
	{
		frame->a.cont[i][0] = frame->a.cont[i - 1][0];
		frame->a.cont[i][1] = frame->a.cont[i - 1][1];
		i--;
	}
	frame->a.cont[i][0] = value;
	frame->a.cont[i][1] = index;
	if (v == 1)
		write(1, "rra\n", 4);
	else if (v == 0)
		print_stack(*frame);
}

void	swap_a(t_stack *stack)
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

void	pa(t_frame *frame, int v)
{
	int value;
	int index;
	int i;

	if (frame->b.dim == 0)
		return ;
	value = frame->b.cont[0][0];
	index = frame->b.cont[0][1];
	i = 0;
	while (i < frame->b.dim - 1)
	{
		frame->b.cont[i][0] = frame->b.cont[i + 1][0];
		frame->b.cont[i][1] = frame->b.cont[i + 1][1];
		i++;
	}
	frame->b.dim--;
	frame->a.dim++;
	swap_a(&frame->a);
	frame->a.cont[0][0] = value;
	frame->a.cont[0][1] = index;
	if (v)
		write(1, "pa\n", 3);
	else
		print_stack(*frame);
}
