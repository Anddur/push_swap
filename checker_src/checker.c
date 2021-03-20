/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 11:13:52 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/20 12:11:43 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		check_op(char *cmd)
{
	if (!ft_strcmp(cmd, "pa") || !ft_strcmp(cmd, "pb") ||
	!ft_strcmp(cmd, "ra") || !ft_strcmp(cmd, "rb") || !ft_strcmp(cmd, "sa") ||
	!ft_strcmp(cmd, "sb") || !ft_strcmp(cmd, "rra") || !ft_strcmp(cmd, "rrb") ||
	!ft_strcmp(cmd, "rr") || !ft_strcmp(cmd, "rrr") || !ft_strcmp(cmd, "ss"))
		return (1);
	return (0);
}

void	decide_op(char *cmd, t_frame *frame)
{
	if (!ft_strcmp(cmd, "pa"))
		pa(frame, 0);
	if (!ft_strcmp(cmd, "pb"))
		pb(frame, 0);
	if (!ft_strcmp(cmd, "ra"))
		ra(&frame->a, 0);
	if (!ft_strcmp(cmd, "rb"))
		rb(&frame->b, 0);
	if (!ft_strcmp(cmd, "sa"))
		sa(&frame->a, 0);
	if (!ft_strcmp(cmd, "sb"))
		sb(&frame->b, 0);
	if (!ft_strcmp(cmd, "rra"))
		rra(&frame->a, 0);
	if (!ft_strcmp(cmd, "rrb"))
		rrb(&frame->b, 0);
	if (!ft_strcmp(cmd, "rr"))
		rr(frame, 0);
	if (!ft_strcmp(cmd, "rrr"))
		rrr(frame, 0);
	if (!ft_strcmp(cmd, "ss"))
		ss(frame, 0);
}

int		is_order(t_frame frame)
{
	int i;

	i = 0;
	if (frame.b.dim > 0)
		return (0);
	while (i < frame.a.dim - 1)
	{
		if (frame.a.cont[i][0] > frame.a.cont[i + 1][0])
			return (0);
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_frame	frame;
	char	**arg;
	t_stack	stack[2];
	char	*cmd;
	int		flag;

	flag = 0;
	if (!ft_memcmp(argv[1], "-v", 2))
		flag = 1;
	arg = parse_input(argv, argc);
	stack[0] = create_stack(ft_arrlen(arg));
	stack[1] = create_stack(ft_arrlen(arg));
	frame = create_frame(stack[0], stack[1]);
	fill_stack(arg, &frame.a);
	while (get_next_line(0, &cmd))
	{
		if (!check_op(cmd))
			exit_error();
		decide_op(cmd, &frame);
		if (flag)
			print_stack(frame);
	}
	if (!is_order(frame))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free_arg(arg);
	free_frame(stack[0], stack[1], ft_arrlen(arg));
}
