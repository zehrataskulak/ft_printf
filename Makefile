NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_find_type.c ft_itoa.c ft_uitoa.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re