/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 10:19:25 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/20 13:18:11 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int			int_dimension(int n)
{
	int size;

	size = 0;
	if (n < 0)
	{
		size = 1;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

void		print_stack(t_frame frame)
{
	int i;
	int size1;
	int size2;

	i = 0;
	write(1, WHTBLK"  STACK A  "NRM, 25);
	write(1, "|", 1);
	write(1, WHTBLK"  STACK B  "NRM, 25);
	write(1, "\n", 1);
	while (i <= frame.a.dim + frame.b.dim - 1)
	{
		size1 = int_dimension(frame.a.cont[i][0]);
		size2 = int_dimension(frame.b.cont[i][0]);
		if (i < frame.a.dim)
		{
			write(1, "          ", 10 - int_dimension(frame.a.cont[i][0]));
			write(1, ft_itoa(frame.a.cont[i][0]), int_dimension(frame.a.cont[i][0]));
			write(1, " ", 1);
		}
		else
			write(1, "           ", 11);
		write(1, "|", 1);
		if (i < frame.b.dim)
		{
			write(1, " ", 1);
			write(1, ft_itoa(frame.b.cont[i][0]), int_dimension(frame.b.cont[i][0]));
			write(1, "          ", 11 - int_dimension(frame.b.cont[i][0]));
		}
		else
			write(1, "          ", 11);
		write(1, "\n", 1);
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
