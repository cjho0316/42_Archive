NAME	= shell
LIBFT	= libft
LIBFT_A	= libft.a

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

SRCS	= main.c \
		env_func.c\
		ft_pwd.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
			make all -C $(LIBFT) /
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lreadline -Llibft -lft

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all bonus clean fclean re