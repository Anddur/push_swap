/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:44:46 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/20 17:49:23 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_frame	frame;
	int		*subseq;
	int		sub_len;
	char	**arg;
	t_stack	stack[2];

	arg = parse_input(argv, argc);
	subseq = NULL;
	sub_len = 0;
	stack[0] = create_stack(ft_arrlen(arg));
	stack[1] = create_stack(ft_arrlen(arg));
	frame = create_frame(stack[0], stack[1]);
	fill_stack(arg, &frame.a);
	if (ft_arrlen(arg) == 3)
		stupid_sort(&frame.a);
	else if (ft_arrlen(arg) == 5)
		stupid_sort_five(&frame, subseq);
	else
	{
		enumerate_stack(&frame.a);
		subseq = calc_max_subseq(&frame.a, &sub_len);
		solve(&frame, subseq, sub_len, frame.a.dim);
	}
	free_arg(arg);
	free_frame(stack[0], stack[1], ft_arrlen(arg), subseq);
}
