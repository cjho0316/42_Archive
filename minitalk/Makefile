# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 16:38:39 by jang-cho          #+#    #+#              #
#    Updated: 2022/09/24 01:12:12 by jang-cho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc -Wall -Wextra -Werror

NAME 	=	minitalk.a
SOURCES = 	client.c\
			server.c\
			utils.c\
			utils1.c\


OBJECTS = $(SOURCES:.c=.o)

%.o: %.c
	$(GCC) -c $< -o $@

# need to add new bonus rule

$(NAME) : $(OBJECTS)
	ar cr $(NAME) $(OBJECTS)

all: $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re