/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 11:13:52 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/20 17:49:43 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int argc, char **argv)
{
	t_frame	frame;
	char	**arg;
	t_stack	stack[2];
	int		flag;

	flag = 0;
	if (!ft_memcmp(argv[1], "-v", 2))
		flag = 1;
	arg = parse_input(argv, argc);
	stack[0] = create_stack(ft_arrlen(arg));
	stack[1] = create_stack(ft_arrlen(arg));
	frame = create_frame(stack[0], stack[1]);
	fill_stack(arg, &frame.a);
	checker(frame, flag);
	free_arg(arg);
	free_frame(stack[0], stack[1], ft_arrlen(arg));
}
