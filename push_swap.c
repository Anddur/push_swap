/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:44:46 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/17 12:14:03 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_frame	frame;

	if (argc < 2)
		exit(0);
	frame = create_frame(argc);
	fill_stack(argv, argc, &frame.a);
	enumerate_stack(&frame.a);
	calc_max_subseq(&frame.a);
	print_stack(frame.a);
}
