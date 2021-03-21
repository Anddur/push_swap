/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 10:50:33 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/21 11:49:27 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_a(int i, t_frame frame)
{
	int j;

	if (frame.a.dim > i)
		j = 182 - frame.a.cont[i][1];
	else if (frame.b.dim - frame.a.dim == 1 && i == frame.a.dim)
		j = 182;
	else if (frame.b.dim > frame.a.dim)
		j = 182;
	else
		j = 0;
	while (j-- > 0)
		write(1, " ", 1);
	write(1, CYNBLK, 10);
	j = 0;
	while (j++ < frame.a.cont[i][1] && frame.a.dim > i)
		write(1, " ", 1);
}

void		print_b(int i, t_frame frame)
{
	int j;

	j = 0;
	while (j++ < frame.b.cont[i][1] && frame.b.dim > i)
	{
		write(1, MAGBLK, 10);
		write(1, " ", 1);
		write(1, NRM, 4);
	}
}

void		print_stack(t_frame frame)
{
	int i;

	write(1, "\033[2J", 4);
	i = 0;
	while (i <= frame.a.dim + frame.b.dim - 1)
	{
		print_a(i, frame);
		if (i < frame.a.dim || i < frame.b.dim)
			write(1, NRM" | ", 7);
		write(1, NRM, 4);
		print_b(i, frame);
		write(1, "\n\n", 2);
		i++;
	}
	i = 0;
	while (i++ < 500000000)
	{
	}
}
