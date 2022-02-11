/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayesha <cayesha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:43:44 by cayesha           #+#    #+#             */
/*   Updated: 2022/02/11 16:53:49 by cayesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void full_game(char *str, int length, int heigth, data_windows *window)
{
	int		fd;
	char	*s;
	int		i;
	int		j;

	fd = open(str, O_RDONLY);
	i = 0;
	while (i < heigth)
	{
		j = 0;
		s = get_next_line(fd);
		while (j < length)
		{
			window->game[i][j] = s[j];
			j++;
		}
		free(s);
		i++;
	}
	window->column = length;
	window->row = heigth;
}

void update_data(data_windows *windows, int length, int heigth, char *str)
{
	int	i;

	i = 0;
	windows->game = malloc(sizeof(char *) * heigth + 1);
	while (i < heigth)
	{
		windows->game[i] = malloc(length + 1);
		i++;
	}
	full_game(str, length, heigth, windows);
}

void update_windows(data_windows *windows, char *str)
{
	int		fd;
	char	*s;
	int		length;
	int		heigth;

	fd = open(str, O_RDONLY);
	s = get_next_line(fd);
	if (s != NULL)
	{
		heigth = 1;
		length = ft_strlen(s) - 1;
	}
	s = get_next_line(fd);
	while (s != NULL)
	{
		heigth++;
		s = get_next_line(fd);
		free(s);
	}
	windows->width_window = length * 50;
	windows->heigth_window = heigth * 50;
	update_data(windows, length, heigth, str);
	close(fd);
}

/*
void print_svoistva(data_windows window)
{
	printf("map_column = %d\t map_row = %d\n", window.column, window.row);
	printf("\t\tMAP\n");
	for(int i = 0; i < window.row; i++)
	{
		printf("\t");
		for(int j = 0; j < window.column; j++)
			printf("%c", window.game[i][j]);
		printf("\n");
	}
}*/

void engine(data_windows *window)
{
	mlx_loop_hook(window->mlx, timer, window);	
	mlx_key_hook(window->win, key_hook, window);
	mlx_loop(window->mlx);	
}

int	main(int argc, char **argv)
{
	data_windows window;
	if (check(argc, argv, &window) == 0)
	{
		write(2, "\nError\n", 6);
		return (0);
	}
	else
		write(1, "right\n", 7);
	update_windows(&window, argv[1]);
	//print_svoistva(window);
	window.bot.score = -1;
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, window.width_window, 
		window.heigth_window, "TEST");
	load_picture(&window);////////////////+++++++++++++
	draw_map(&window);////////////////////++++++++++++++++
	draw_score(&window);//////////////////+++++++++++++
	engine(&window);
	mlx_loop(window.mlx);	
}
