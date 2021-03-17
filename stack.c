/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 10:19:25 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/17 11:56:49 by aduregon         ###   ########.fr       */
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
			free_stack(i - 1, stack);
		i++;
	}
	stack.dim = 0;
	return (stack);
}

void		fill_stack(char **argv, int argc, t_stack *stack)
{
	int	i;
	int atoi;

	i = 0;
	while (i < argc - 1)
	{
		atoi = ft_atoi(argv[i + 1]);
		stack->cont[i][0] = atoi;
		stack->cont[i][1] = 0;
		stack->dim++;
		i++;
	}
}

void		print_stack(t_stack stack)
{
	int i;

	i = 0;
	while (i <= stack.dim - 1)
	{
		printf("[%d] {%d}\n", stack.cont[i][0], stack.cont[i][1]);
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
// void		destroy_stack(t_stack stack)
// {
// 	stack.dim = 0;
// 	free(stack.cont);
// }

// void		stack_push(t_stack *stack, int n)
// {
// 	stack->dim++;
// 	stack->cont[stack->dim] = n;
// }

// int			stack_pop(t_stack stack)
// {
// 	int		n;

// 	n = stack.cont[stack.dim];
// 	stack.dim--;
// 	return (n);
// }
