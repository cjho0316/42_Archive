GCC = gcc -Wall -Wextra -Werror

SRCDIR = srcs
INCDIR = includes

NAME = libft.a
SOURCES = $(SRCDIR)/ft_putchar.c $(SRCDIR)/ft_swap.c $(SRCDIR)/ft_putstr.c $(SRCDIR)/ft_strlen.c $(SRCDIR)/ft_strcmp.c
OBJECTS = $(SOURCES:.c=.o)

%.o: %.c
	$(GCC) -c $< -o $@ -I $(INCDIR)

$(NAME) : $(OBJECTS)
	ar cr $(NAME) $(OBJECTS)

all: $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re
