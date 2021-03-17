NAME	=   libft.a
SRCS	=	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_dclst_manage.c \
			ft_dclst_manage2.c \
			ft_dlst_manage.c \
			ft_dlst_manage2.c \
			ft_intlen.c \
			ft_isalpha.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_is_in_charset.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_base.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_stoa_base.c \
			ft_strchr.c \
			ft_strcmp.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_lstnew.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstadd_sorted.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstfind.c \
			ft_lstiter.c \
			ft_lstlen.c \
			ft_lstmap.c \
			ft_lstrm_if.c \
			ft_lstrm.c \
			get_next_line.c \
			get_next_line_utils.c

OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)
CC 		= gcc
RM		= rm -f
LIBC	= ar -rcs
FLAGS	= -Wall -Wextra -Werror
INCS	= .

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

$(NAME): ${OBJS}
	${LIBC} $(NAME) $(OBJS)

all: $(NAME)

bonus: $(NAME) $(OBJS_B)
	${LIBC} $(NAME) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_B)

re: fclean all

.PHONY: all bonus clean fclean re .c.o
