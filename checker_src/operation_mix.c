/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_mix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:32:49 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/20 11:16:00 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rr(t_frame *frame, int v)
{
	if (frame->a.dim > 1)
		ra(&frame->a, 0);
	if (frame->b.dim > 1)
		rb(&frame->b, 0);
	if (v)
		write(1, "rr\n", 3);
}

void	rrr(t_frame *frame, int v)
{
	if (frame->a.dim > 1)
		rra(&frame->a, 0);
	if (frame->b.dim > 1)
		rrb(&frame->b, 0);
	if (v)
		write(1, "rrr\n", 4);
}

void	ss(t_frame *frame, int v)
{
	sa(&frame->a, 0);
	sb(&frame->b, 0);
	if (v)
		write(1, "ss\n", 3);
}
