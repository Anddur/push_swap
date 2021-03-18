/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:44:46 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/18 19:35:13 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_min_stack(t_stack *stack)
{
	int min;
	int i;
	int pos;

	i = 0;
	min = stack->cont[i][0];
	pos = i;
	while (i < stack->dim)
	{
		if (min > stack->cont[i][0])
			min = stack->cont[i][0];
		i++;
	}
	return (min);
}

int		find_max_stack(t_stack *stack)
{
	int max;
	int i;
	int pos;

	i = 0;
	max = stack->cont[i][0];
	pos = i;
	while (i < stack->dim)
	{
		if (max < stack->cont[i][0])
			max = stack->cont[i][0];
		i++;
	}
	return (max);
}

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

int		main(int argc, char **argv)
{
	t_frame	frame;
	int		*subseq;
	int		sub_len;

	sub_len = 0;
	if (argc < 2)
		exit(0);
	frame = create_frame(argc);
	fill_stack(argv, argc, &frame.a);
	if (argc == 4)
		stupid_sort(&frame.a);
	else
	{
		enumerate_stack(&frame.a);
		subseq = calc_max_subseq(&frame.a, &sub_len);
		solve(&frame, subseq, sub_len, frame.a.dim);
	}
	//free_stack(&frame);
	sleep(100000000);
}
