# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 16:15:44 by jang-cho          #+#    #+#              #
#    Updated: 2022/12/28 16:15:46 by jang-cho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
LIBFT	=	libft
LIBFT_A	=	libft.a
BONUS	=	checker

CC		= cc
CFLAG	= -Wall -Wextra -Werror

RM		= rm -f

SRCS	= push_swap.c \
			deque1.c \
			deque2.c \
			algorithmn1.c \
			algorithmn2.c \
			instruction1.c \
			instruction2.c \
			instruction3.c \
			instruction4.c \
			library1.c \
			library2.c \
			parsing1.c \
			parsing2.c

# SRCS_B = checker.c \
# 		 sort.c sort_utils.c \
# 		 stacks.c \
# 		 array.c \
# 		 command.c command_rot.c command_rerot.c command_utils.c \
# 		 validater.c \
# 		 utils.c \
# 		 get_next_line.c get_next_line_utils.c\
# 		 bonus/bonus_command.c bonus/bonus_command_rerot.c bonus/bonus_command_rot.c
		
OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)
LIBC	= ar rc

ifdef WITH_BONUS
	NAME = $(BONUS)
	OBJECTS = $(OBJS_B)
else
	OBJECTS = $(OBJS)
endif

all : $(NAME)

$(NAME):	$(OBJECTS)
			make all -C $(LIBFT)/
			$(CC) -o $(NAME) $(OBJECTS) -Llibft	-lft

%.o	: %.c
			$(CC)	$(CFLAG) -c $^	-I./ -o $@

bonus	:
		make WITH_BONUS=1 all
clean	:
		$(RM) -f $(OBJS) $(OBJS_B)
		make clean -C $(LIBFT)

fclean	: clean
		$(RM) -f $(NAME)
		$(RM) -f $(LIBFT_A)
		$(RM) -f $(BONUS)
		make fclean -C $(LIBFT)

re : fclean all

.PHONY : all clean fclean re bonus