/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_calculator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 12:19:51 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/19 12:20:33 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		count_op(int a, int b)
{
	if ((a * b) > 0)
		return (MAX(ABS(a), ABS(b)));
	else
		return (ABS(a) + ABS(b));
}

void	compare_op(int tmp1, int tmp2, int *a, int *b)
{
	if (count_op(tmp1, tmp2) < count_op(*a, *b))
	{
		*a = tmp1;
		*b = tmp2;
	}
}
