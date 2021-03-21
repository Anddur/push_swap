/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_mix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:32:49 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/21 10:48:45 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_frame *frame, int v)
{
	if (frame->a.dim > 1)
		ra(frame, -1);
	if (frame->b.dim > 1)
		rb(frame, -1);
	if (v)
		write(1, "rr\n", 3);
	else
		print_stack(*frame);
}

void	rrr(t_frame *frame, int v)
{
	if (frame->a.dim > 1)
		rra(frame, -1);
	if (frame->b.dim > 1)
		rrb(frame, -1);
	if (v)
		write(1, "rrr\n", 4);
	else
		print_stack(*frame);
}
