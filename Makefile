NAME1	=	push_swap
NAME2	=	checker

LIBFT	=	./libft/libft.a

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

SRCS1	=	push_swap_src/push_swap.c \
			push_swap_src/frame.c \
			push_swap_src/stack.c \
			push_swap_src/free.c \
			push_swap_src/enumerate_stack.c \
			push_swap_src/max_subseq.c \
			push_swap_src/operation_a.c \
			push_swap_src/operation_b.c \
			push_swap_src/operation_mix.c \
			push_swap_src/algorithm.c \
			push_swap_src/divide_stack.c \
			push_swap_src/merge_stack.c \
			push_swap_src/min_stack.c \
			push_swap_src/op_calculator.c \
			push_swap_src/parse_input.c \
			push_swap_src/stupid_sort.c

SRCS2	=	checker_src/checker.c \
			checker_src/frame.c \
			checker_src/free.c \
			checker_src/operation_a.c \
			checker_src/operation_b.c \
			checker_src/operation_mix.c \
			checker_src/parse_input.c \
			checker_src/stack.c \
			checker_src/verbose.c \
			checker_src/print_exit.c \
			checker_src/check_stack.c

OBJS1	=	$(SRCS1:.c=.o)
OBJS2	=	$(SRCS2:.c=.o)

%.o			:	%.c
			@$(CC) $(CFLAGS) -c $^ -o $@

$(NAME1)	:	$(OBJS1)
			@make -C ./libft
			@$(CC) $(CFLAGS) -o $(NAME1) $(LIBFT) $(OBJS1)
			@echo "\033[0;32mPUSH_SWAP COMPILED\033[0;0m"

$(NAME2)	:	$(OBJS2)
			@make -C ./libft
			@$(CC) $(CFLAGS) -o $(NAME2) $(LIBFT) $(OBJS2)
			@echo "\033[0;32mCHECKER COMPILED\033[0;0m"

all		:	$(NAME1) $(NAME2)

clean	:	
			@$(RM) push_swap_src/*.o checker_src/*.o
			@make clean -C ./libft

fclean	:	clean
			@$(RM) $(NAME1) $(NAME2)
			@make fclean -C ./libft
			@echo "\033[0;33mCHECKER CLEAN\033[0;0m"
			@echo "\033[0;33mPUSH_SWAP CLEAN\033[0;0m"

bonus	:

re		: fclean all

.PHONY	:	all clean fclean bonus re checker push_swap