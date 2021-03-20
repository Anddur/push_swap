/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:28:13 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/20 10:04:45 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_frame(t_stack a, t_stack b, int arg)
{
	free_stack(a, arg);
	free_stack(b, arg);
}

void	free_stack(t_stack stack, int argc)
{
	int i;

	i = 0;
	while (i < argc)
	{
		free(stack.cont[i++]);
	}
	free(stack.cont);
}

void	free_arg(char **arg)
{
	int i;
	int dim;

	i = 0;
	dim = ft_arrlen(arg);
	while (i < dim)
		free(arg[i++]);
	free(arg);
}

void	exit_error(void)
{
	write(1, "Error\n", 6);
	exit(-1);
}
