/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 11:52:56 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/17 09:47:07 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct	s_stack
{
	int			dim;
	int			*cont;
}				t_stack;

t_stack		create_stack(int n);
void		destroy_stack(t_stack stack);
void		stack_push(t_stack *stack, int n);
int			stack_pop(t_stack stack);

#endif