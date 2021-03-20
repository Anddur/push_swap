/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:47:13 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/20 17:13:32 by aduregon         ###   ########.fr       */
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

void	checker(t_frame frame, int flag)
{
	char	*cmd;

	while (get_next_line(0, &cmd))
	{
		if (!check_op(cmd))
			exit_error();
		decide_op(cmd, &frame);
		free(cmd);
		if (flag)
			print_stack(frame);
	}
	if (!is_order(frame))
		(flag == 1) ? print_fail() : write(1, "KO\n", 3);
	else
		(flag == 1) ? print_success() : write(1, "OK\n", 3);
	free(cmd);
}
