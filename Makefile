NAME = ftprintf.a
SRCS = $(addprefix src/, ft_print.c ft_printf.c ft_puts.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c ft_printf.h
	@gcc -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all