/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:42:03 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/21 10:13:58 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_last_val(t_frame *frame, int *subseq, int sub_len, int vis)
{
	int j;
	int flag;

	while (1)
	{
		j = 0;
		flag = 0;
		while (j < sub_len)
		{
			if (frame->a.cont[frame->a.dim - 1][0] == subseq[j])
				flag = 1;
			j++;
		}
		if (!flag)
		{
			rra(frame, vis);
			pb(frame, vis);
		}
		else
			break ;
	}
}

void	divide_stack(t_frame *frame, int *subseq, int sub_len, int vis)
{
	int j;
	int flag;

	check_last_val(frame, subseq, sub_len, vis);
	while (frame->a.dim != sub_len)
	{
		j = 0;
		flag = 0;
		while (j < sub_len)
		{
			if (frame->a.cont[0][0] == subseq[j])
				flag = 1;
			j++;
		}
		if (flag)
			ra(frame, vis);
		else
			pb(frame, vis);
	}
}
