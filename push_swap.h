/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:45:56 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/18 12:49:23 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct	s_stack
{
	int			dim;
	int			**cont;
}				t_stack;

typedef struct	s_frame
{
	t_stack		a;
	t_stack		b;
}				t_frame;

t_frame		create_frame(int argc);
t_stack		create_stack(int n);
void		destroy_stack(t_stack stack);
void		stack_push(t_stack *stack, int n);
int			stack_pop(t_stack stack);
void		fill_stack(char **argv, int argc, t_stack *stack);
void		print_stack(t_frame frame);
void		enumerate_stack(t_stack *stack);
void		free_stack(int i, t_stack stack);
int			*copy_stack(t_stack *stack);
int			*calc_max_subseq(t_stack *stack, int *sub_len);
void		sa(t_stack *stack, int v);
void		ra(t_stack *stack, int v);
void		rra(t_stack *stack, int v);
void		pa(t_frame *frame, int v);
void		sb(t_stack *stack, int v);
void		rb(t_stack *stack, int v);
void		rrb(t_stack *stack, int v);
void		pb(t_frame *frame, int v);
void		rr(t_frame *frame, int v);
void		rrr(t_frame *frame, int v);
void		solve(t_frame *frame, int *subseq, int sub_len, int stack_len);

#endif
