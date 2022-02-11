NAME = so_long
SRC = ./gnl/get_next_line.c ./gnl/get_next_line_utils.c ./check/check_true.c ./check/mini_functions.c ./ft_itoa.c ./draw_animation.c ./move.c ./draw_pictures.c
OBJ = get_next_line.o get_next_line_utils.o check_true.o mini_functions.o ft_itoa.o  draw_animation.o move.o draw_pictures.o ./printf/ft_printf.o

MAIN_SRC = main.c load.c draw_map.c	timer.c draw_score.c
MAIN_OBJ = main.o load.o draw_map.o timer.o draw_score.o

all: $(NAME)

$(NAME): $(OBJ) $(MAIN_OBJ)
	make -C ./printf
	cc -Lminilibx -lmlx -framework OpenGL -framework AppKit  $(OBJ) $(MAIN_OBJ) ./printf/libftprintf.a -o so_long

$(OBJ): $(SRC) ./gnl/get_next_line.h
	cc -Wall -Werror -Wextra -I./gnl/ -c $(SRC)

$(MAIN_OBJ): $(MAIN_SRC) so_long.h
	cc -Wall -Werror -Wextra -c $(MAIN_SRC)

clean:
	make fclean -C ./printf
	rm -rf *.o

fclean: clean
	make fclean -C ./printf
	rm -rf $(NAME)

re: fclean all