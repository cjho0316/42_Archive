# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 17:35:53 by jang-cho          #+#    #+#              #
#    Updated: 2022/10/07 15:32:31 by jang-cho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS		= so_long.c \
			  images.c \
			  key_binding.c \
			  map.c \
			  utils.c \
			  gnl.c \
			  gnl_utils.c \
			  map_checker.c

OBJS		= $(SRCS:%.c=%.o)

LIBC		= ar rc

FLAGS		= -Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		make all -C $(LIBFT)/
		gcc -o $(NAME) $(OBJS) -Llibft -lft -lmlx -framework OpenGL -framework AppKit

%.o			:	%.c
		gcc $(FLAGS) -c $^ -I./ -o $@

clean		:
		rm -f $(OBJS)
		make clean -C $(LIBFT)

fclean		:	clean
		rm -f $(NAME)
		rm -f $(LIBFT_LIB)
		make fclean -C $(LIBFT)

re			:	fclean all

.PHONY		:	all clean fclean re bonus
