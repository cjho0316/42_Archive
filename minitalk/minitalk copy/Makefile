# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 16:38:39 by jang-cho          #+#    #+#              #
#    Updated: 2022/10/02 16:21:50 by jang-cho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = server_bonus.c client_bonus.c
OBJECTS = $(SOURCES:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = minitalk

all : server client

bonus : server_bonus client_bonus

server : server.o libft
	$(CC) -o $@ $< -Llibft -lft

server_bonus : server.o libft
	$(CC) -o $@ $< -Llibft -lft

client : client.o libft
	$(CC) -o $@ $< -Llibft -lft

client_bonus : client.o libft
	$(CC) -o $@ $< -Llibft -lft

%.o : %.c
	$(CC) -c $(CFLAGS) $?

libft :
	make -C libft

clean : 
	rm -f $(OBJECTS)
	make -C libft clean

fclean : clean
	rm -f server client server_bonus client_bonus libft/libft.a

re : fclean all

.PHONY : all libft clean fclean all bonus
