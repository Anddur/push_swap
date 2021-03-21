/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:45:56 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/21 10:51:36 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

# define MAX(x, y) ((x > y) ? x : y)
# define MIN(x, y) ((x < y) ? x : y)
# define ABS(x) ((x > 0) ? x : -x)

# define NRM  "\x1B[0m"
# define BLK  "\x1B[30m"
# define RED  "\x1B[31m"
# define GRN  "\x1B[32m"
# define YEL  "\x1B[33m"
# define BLU  "\x1B[34m"
# define MAG  "\x1B[35m"
# define PNK  "\033[255;161;244m"
# define CYN  "\x1B[36m"
# define WHT  "\x1B[37m"
# define GRY  "\e[0;37m"

# define BRED  "\x1B[41m"
# define BGRN  "\x1B[42m"
# define BYEL  "\x1B[43m"
# define BBLU  "\x1B[44m"
# define BMAG  "\x1B[45m"
# define BCYN  "\x1B[46m"
# define BWHT  "\x1B[47m"

# define WHTBLK "\x1B[47m\x1B[30m"
# define CYNBLK "\x1B[46m\x1B[30m"
# define MAGBLK "\x1B[45m\x1B[30m"
# define MAGWHT "\x1B[45m\x1B[37m"
# define REDWHT "\x1B[41m\x1B[37m"

typedef struct	s_stack
{
	int			dim;
	int			**cont;
}				t_stack;

typedef struct	s_frame
{
	t_stack		a;
	t_stack		b;
	int			*subseq;
	int			sub_len;
}				t_frame;

t_frame			create_frame(t_stack a, t_stack b);
t_stack			create_stack(int n);
void			destroy_stack(t_stack stack);
void			stack_push(t_stack *stack, int n);
int				stack_pop(t_stack stack);
void			fill_stack(char **arg, t_stack *stack);
void			print_stack(t_frame frame);
void			enumerate_stack(t_stack *stack);
void			free_frame(t_stack a, t_stack b, int arg, int *subseq);
void			free_stack(t_stack stack, int argc);
int				*copy_stack(t_stack *stack);
int				*calc_max_subseq(t_stack *stack, int *sub_len);
void			sa(t_frame *frame, int v);
void			ra(t_frame *frame, int v);
void			rra(t_frame *frame, int v);
void			pa(t_frame *frame, int v);
void			sb(t_frame *frame, int v);
void			rb(t_frame *frame, int v);
void			rrb(t_frame *frame, int v);
void			pb(t_frame *frame, int v);
void			rr(t_frame *frame, int v);
void			rrr(t_frame *frame, int v);
void			solve(t_frame *frame, int stack_len, int vis);
void			divide_stack(t_frame *frame, int *subseq, int sub_len, int vis);
void			merge_stack(t_frame *frame, int vis);
int				find_min(int *arr, int len);
int				find_min(int *arr, int len);
void			*ft_memmove_int(void *dest, const void *src, size_t n);
int				count_op(int a, int b);
void			compare_op(int tmp1, int tmp2, int *a, int *b);
char			**parse_input(char **argv, int argc);
int				ft_arrlen(char **arr);
void			free_arg(char **arg);
void			stupid_sort(t_frame *frame, int vis);
void			stupid_sort_five(t_frame *frame, int *subseq, int vis);
int				find_max_stack(t_stack *stack);
int				find_min_stack(t_stack *stack);
void			stack_align(t_frame *frame, int vis);
void			exit_error(void);

#endif
