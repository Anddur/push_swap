/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 11:52:56 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/20 16:47:30 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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
}				t_frame;

t_frame			create_frame(t_stack a, t_stack b);
void			free_frame(t_stack a, t_stack b, int arg);
void			free_stack(t_stack stack, int argc);
void			free_arg(char **arg);
void			exit_error(void);
void			sa(t_stack *stack, int v);
void			ra(t_stack *stack, int v);
void			rra(t_stack *stack, int v);
void			pa(t_frame *frame, int v);
void			sb(t_stack *stack, int v);
void			rb(t_stack *stack, int v);
void			rrb(t_stack *stack, int v);
void			pb(t_frame *frame, int v);
void			rr(t_frame *frame, int v);
void			rrr(t_frame *frame, int v);
void			ss(t_frame *frame, int v);
char			**parse_input(char **argv, int argc);
t_stack			create_stack(int n);
int				ft_arrlen(char **arr);
void			fill_stack(char **arg, t_stack *stack);
void			print_stack(t_frame frame);
int				*copy_stack(t_stack *stack);
void			print_success(void);
void			print_fail(void);
int				check_op(char *cmd);
void			decide_op(char *cmd, t_frame *frame);
int				is_order(t_frame frame);
void			checker(t_frame frame, int flag);

#endif
