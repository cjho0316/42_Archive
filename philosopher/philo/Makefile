# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 11:37:44 by jang-cho          #+#    #+#              #
#    Updated: 2023/02/12 11:38:10 by jang-cho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = main.c \
		utils.c \
		init.c \
		philo.c \
		free.c \

CC = cc
FLAGS = -Wall -Wextra -Werror 
RM = rm -rf

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

re: fclean all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

.PHONY: all clean fclean re
