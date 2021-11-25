NAME = ft_printf.a

HEAD = ft_printf.h

SRCS = $(wildcard src/*.c)

OBJS = $(addprefix obj/, $(patsubst %.c, %.o, $(notdir $(SRCS))))

FLAG = -Wall -Wextra -Werror

CC = gcc 

AR = ar rcs

RM = rm -rf

all: $(NAME)

$(OBJS): $(HEAD)
	@ $(CC) $(FLAG) -c $(addprefix src/, $(patsubst %.o, %.c, $(notdir $@))) -o $(addprefix obj/, $(notdir $@))

$(NAME): $(OBJS) $(HEAD)
	@ $(AR) $(NAME) $(OBJS)

clean:
	@ $(RM) $(OBJS)

fclean: clean
	@ $(RM) $(NAME)

re: fclean all