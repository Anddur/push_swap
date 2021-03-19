/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:45:56 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/19 18:52:38 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"

# define MAX(x, y) ((x > y) ? x : y)
# define MIN(x, y) ((x < y) ? x : y)
# define ABS(x) ((x > 0) ? x : -x)

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

t_frame		create_frame(t_stack a, t_stack b);
t_stack		create_stack(int n);
void		destroy_stack(t_stack stack);
void		stack_push(t_stack *stack, int n);
int			stack_pop(t_stack stack);
void		fill_stack(char **arg, int argc, t_stack *stack);
void		print_stack(t_frame frame);
void		enumerate_stack(t_stack *stack);
void		free_frame(t_stack a, t_stack b, int arg, int *subseq);
void		free_stack(t_stack stack, int argc);
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
void		divide_stack(t_frame *frame, int *subseq, int sub_len);
void		merge_stack(t_frame *frame);
int			find_min(int *arr, int len);
int			find_min(int *arr, int len);
void		*ft_memmove_int(void *dest, const void *src, size_t n);
int			count_op(int a, int b);
void		compare_op(int tmp1, int tmp2, int *a, int *b);
char		**parse_input(char **argv, int argc);
int			ft_arrlen(char **arr);
void		free_arg(char **arg);
void		stupid_sort(t_stack *stack);
void		stupid_sort_five(t_frame *frame, int *subseq);
int			find_max_stack(t_stack *stack);
int			find_min_stack(t_stack *stack);
void		stack_align(t_stack stack);
void		exit_error(void);

#endif
