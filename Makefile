CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

SRC = ft_printf.c ft_putchar.c ft_putnbr.c ft_puthex.c ft_putptr.c
OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

AR = ar -rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
