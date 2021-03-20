/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 10:19:25 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/20 09:41:53 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		create_stack(int n)
{
	t_stack	stack;
	int		i;

	i = 0;
	if (!(stack.cont = ft_calloc(n, sizeof(int *))))
		exit(0);
	while (i < n)
	{
		if (!(stack.cont[i] = ft_calloc(2, sizeof(int))))
			free_stack(stack, n);
		i++;
	}
	stack.dim = 0;
	return (stack);
}

int			ft_arrlen(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void		fill_stack(char **arg, t_stack *stack)
{
	int	i;
	int atoi;

	i = 0;
	while (i < ft_arrlen(arg))
	{
		atoi = ft_atoi(arg[i]);
		stack->cont[i][0] = atoi;
		stack->cont[i][1] = 0;
		stack->dim++;
		i++;
	}
}

void		print_stack(t_frame frame)
{
	int i;

	i = 0;
	while (i <= frame.a.dim - 1)
	{
		if (i < frame.a.dim)
			printf("[%d] {%d} | ", frame.a.cont[i][0], frame.a.cont[i][1]);
		else
			printf("          | ");
		if (i < frame.b.dim)
			printf("[%d] {%d} | ", frame.b.cont[i][0], frame.b.cont[i][1]);
		else
			printf("            ");
		puts("");
		i++;
	}
}

int			*copy_stack(t_stack *stack)
{
	int		*copy_stack;
	int		i;

	i = 0;
	if (!(copy_stack = ft_calloc(stack->dim, sizeof(int))))
		exit(0);
	while (i < stack->dim)
	{
		copy_stack[i] = stack->cont[i][0];
		i++;
	}
	return (copy_stack);
}
