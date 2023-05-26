NAME = RPN

CC = c++

FLAGS = -std=c++98 -Wall -Wextra -Werror

RM = rm -f

SRCS = main.cpp\
		

OBJS = ${SRCS:.cpp=.o}

%.o : %.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean :
	$(MAKE) clean
	$(RM) $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re