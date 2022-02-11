#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include "./gnl/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

#define W 13
#define S 1
#define A 0
#define D 2


typedef struct svoistva
{
	int width;
	int height;
	int start;
	int finish;
	int collection;
} data_map;



typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				data_img;

typedef struct s_picture
{
	data_img		pizza1;
	data_img		pizza2;
	data_img		pizza3;
	data_img		hero1;
	data_img		hero2;
	data_img		hero3;
	data_img	door_close;
	data_img	door_open;
	data_img	wall;
	data_img	ground;
}				data_picture;


typedef struct s_player
{
	int		x;
	int		y;
	int		score;
}				player;



typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int width_window;
	int heigth_window;
	int column;
	int row;
	data_picture	pictures;
	data_map	map;
	char **		game;
	player bot;
}				data_windows;

	char	*ft_itoa(int n);

	void init_map(data_windows* window);
	int count_heigth(char *str);
	int full(char *s, data_map *map);
	int count_svoistva(data_map map);

	int check_first(int *fd, data_windows *window, char *str);
	int check_second(data_windows *window, int fd);
	int check_third(int fd, data_windows *window);
	int check_map(char *str, data_windows *window);
	int check(int count, char **strs, data_windows *window);


	void	draw_pizza2(data_windows *window);
	void	draw_pizza1(data_windows *window);
	void	draw_pizza3(data_windows *window);
	void	draw_hero1(data_windows *window);
	void	draw_hero2(data_windows *window);
	void	draw_wall(data_windows *window, int i, int j);
	void	draw_ground(data_windows *window, int i, int j);
	void	draw_exit(data_windows *window, int i, int j);
	void	draw_pizza(data_windows *window, int i, int j);
	void	draw_player(data_windows *window, int i, int j);

	void	load_picture(data_windows *window);

	void	draw_map(data_windows *window);

	void draw_score(data_windows *window);

	void find_exit(data_windows *windows);

	void	move_up(data_windows *window);
	void	move_left(data_windows *window);
	void	move_down(data_windows *window);
	void	move_right(data_windows *window);
	int	key_hook(int key_code, data_windows *window);

	int	timer(data_windows *window);
#endif