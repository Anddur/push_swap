/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:44:46 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/21 11:48:50 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_frame	frame;
	char	**arg;
	t_stack	stack[2];
	int		vis;

	vis = 1;
	if (!ft_strcmp(argv[1], "-v"))
		vis = 0;
	arg = parse_input(argv, argc);
	stack[0] = create_stack(ft_arrlen(arg));
	stack[1] = create_stack(ft_arrlen(arg));
	frame = create_frame(stack[0], stack[1]);
	fill_stack(arg, &frame.a);
	if (ft_arrlen(arg) == 3)
		stupid_sort(&frame, vis);
	else if (ft_arrlen(arg) == 5)
		stupid_sort_five(&frame, frame.subseq, vis);
	else
	{
		enumerate_stack(&frame.a);
		frame.subseq = calc_max_subseq(&frame.a, &frame.sub_len);
		solve(&frame, frame.a.dim, vis);
	}
	free_arg(arg);
	free_frame(stack[0], stack[1], ft_arrlen(arg), frame.subseq);
}
