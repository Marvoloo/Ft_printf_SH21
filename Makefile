NAME = libftprintf.a
SRCS = $(addprefix src/, ft_printf.c ft_puts.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c ft_printf.h
	gcc -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re