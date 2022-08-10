# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/07 05:25:28 by jang-cho          #+#    #+#              #
#    Updated: 2022/08/09 12:55:52 by jang-cho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc -Wall -Wextra -Werror

NAME 	=	libftprintf.a
SOURCES = 	ft_printf.c\
			ft_putchar.c\
			ft_putstr.c\
			ft_putnbr.c\
			ft_putnbr_base.c\
			ft_unsigned_putnbr.c\
			ft_print_mem_address.c\
			ft_strlen.c
			
OBJECTS = $(SOURCES:.c=.o)

%.o: %.c
	$(GCC) -c $< -o $@

$(NAME) : $(OBJECTS)
	ar cr $(NAME) $(OBJECTS)

all: $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
