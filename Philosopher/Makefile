# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 12:11:09 by jang-cho          #+#    #+#              #
#    Updated: 2023/01/20 12:14:47 by jang-cho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
BONUS	=	philo_bonus

CC		= cc
CFLAG	= -Wall -Wextra -Werror

RM		= rm -f

SRCS	= 
#philo mandatory


SRCS_B 	= 
#philo bonus

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
			$(CC) -o $(NAME) $(OBJECTS)

%.o	: %.c
			$(CC)	$(CFLAG) -c $^	-I./ -o $@

bonus	:
		make WITH_BONUS=1 all
clean	:
		$(RM) -f $(OBJS) $(OBJS_B)

fclean	: clean
		$(RM) -f $(NAME)
		$(RM) -f $(BONUS)

re : fclean all

.PHONY : all clean fclean re bonus