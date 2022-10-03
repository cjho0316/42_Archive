# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 16:38:39 by jang-cho          #+#    #+#              #
#    Updated: 2022/10/03 14:52:40 by jang-cho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	server
NAME2			=	client
NAMEB			=	server_bonus
NAMEB2			=	client_bonus
CFLAG			=	-Weror -Wall -Wextra -I.

CC				=	gcc
RM				=	rm -f

SRCS			=	utils1.c \
					utils2.c \
					server.c

SRCS2			=	utils1.c \
					utils2.c \
					client.c

SRCSB			=	utils1_bonus.c \
					utils2_bonus.c \
					server_bonus.c

SRCSB2			=	utils1_bonus.c \
					utils2_bonus.c \
					client_bonus.c

					 
OBJS			= $(SRCS:%.c=%.o)
OBJS2			= $(SRCS2:%.c=%.o)
OBJSB			= $(SRCSB:%.c=%.o)
OBJSB2			= $(SRCSB2:%.c=%.o)

all:			$(NAME) $(NAME2) bonus

$(NAME):		$(OBJS)
				$(CC) $(CFLAG) $(OBJS) -o $(NAME)
				
$(NAME2):		$(OBJS2)
				$(CC) $(CFLAG) $(OBJS2) -o $(NAME2)

bonus:			$(NAMEB) $(NAMEB2) 
				
$(NAMEB):		$(OBJSB)
				$(CC) $(CFLAG) $(OBJSB) -o $(NAMEB)
				
$(NAMEB2):		$(OBJSB2)
				$(CC) $(CFLAG) $(OBJSB2) -o $(NAMEB2)				
clean:
				$(RM) $(OBJS)
				$(RM) $(OBJS2)
				$(RM) $(OBJSB)
				$(RM) $(OBJSB2)

fclean:			clean
				$(RM) $(NAME)
				$(RM) $(NAME2)
				$(RM) $(NAMEB)
				$(RM) $(NAMEB2)

re:				fclean all

.PHONY:			all bonus clean fclean re