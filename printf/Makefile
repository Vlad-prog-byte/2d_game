NAME = libftprintf.a


INC_DIR = ./includes/

SRC = ./srcs/ft_printf.c ./srcs/ft_put_address.c \
	./srcs/ft_put_hexadecimal.c ./srcs/ft_put_unsigned_int.c \
		./srcs/ft_putchar_fd.c ./srcs/ft_putnbr_fd.c ./srcs/ft_putstr_fd.c


HEADER = ./includes/ft_printf.h


OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	ar rcs $(NAME) $?

%.o : %.c $(HEADER)
	gcc -Wall -Wextra -Werror -I $(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
fclean: clean 
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re