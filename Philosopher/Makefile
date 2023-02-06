# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 12:11:09 by jang-cho          #+#    #+#              #
#    Updated: 2023/02/06 18:10:27 by jang-cho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

CC		= cc

CFLAGS	= -Wall -Wextra -Werror 
#-fsanitize=thread -g

SRCS	= 	philo_run.c \
			philo.c \
			philo_init.c \
			philo_util.c \

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all bonus clean fclean re