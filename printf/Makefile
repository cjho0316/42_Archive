GCC = gcc -Wall -Wextra -Werror

NAME 	=	libftprintf.a
SOURCES = 	ft_printf.c\
			ft_putchar.c\
			ft_putstr.c\
			ft_putnbr.c\
			ft_putnbr_base.c\
			ft_unsigned_putnbr.c\
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
