NAME	=	push_swap

LIBFT	=	./libft/libft.a

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

SRCS	=	push_swap.c \
			frame.c \
			stack.c \
			free.c \
			enumerate_stack.c \
			max_subseq.c \
			operation_a.c \
			operation_b.c \
			operation_mix.c \
			algorithm.c \
			divide_stack.c \
			merge_stack.c \
			min_stack.c \
			op_calculator.c \
			parse_input.c \
			stupid_sort.c

OBJS	=	$(SRCS:.c=.o)

%.o	:	%.c
			@$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJS)
			@make -C ./libft
			@$(CC) $(CFLAGS) -o $(NAME) $(LIBFT) $(OBJS)
			@echo "\033[0;32mPUSH_SWAP COMPILED\033[0;0m"

all		:	$(NAME)

clean	:	
			$(RM) $(OBJS)
			@make clean -C ./libft

fclean	:	clean
			@$(RM) $(NAME)
			@make fclean -C ./libft
			@echo "\033[0;31mPUSH_SWAP CLEAN\033[0;0m"

bonus	:

re		: fclean all

.PHONY	:	all clean fclean bonus re