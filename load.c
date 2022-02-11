/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayesha <cayesha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:36:36 by cayesha           #+#    #+#             */
/*   Updated: 2022/02/09 15:21:18 by cayesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	load_picture_part1(data_windows *window)
{
	window->pictures.wall.img = mlx_xpm_file_to_image(window->mlx,
			"/Users/cayesha/Desktop/my_so_long/img/wall.xpm",
			&window->pictures.wall.width, &window->pictures.wall.height);
	window->pictures.ground.img = mlx_xpm_file_to_image(window->mlx,
			"/Users/cayesha/Desktop/my_so_long/img/ground.xpm",
			&window->pictures.ground.width, &window->pictures.ground.height);
	window->pictures.pizza1.img = mlx_xpm_file_to_image(window->mlx,
			"/Users/cayesha/Desktop/my_so_long/img/pizza1.xpm",
			&window->pictures.pizza1.width, &window->pictures.pizza1.height);
	window->pictures.pizza2.img = mlx_xpm_file_to_image(window->mlx,
			"/Users/cayesha/Desktop/my_so_long/img/pizza2.xpm",
			&window->pictures.pizza2.width, &window->pictures.pizza2.height);
	window->pictures.pizza3.img = mlx_xpm_file_to_image(window->mlx,
			"/Users/cayesha/Desktop/my_so_long/img/pizza3.xpm",
			&window->pictures.pizza3.width, &window->pictures.pizza3.height);
}

void	load_picture(data_windows *window)
{
	window->pictures.hero1.img = mlx_xpm_file_to_image(window->mlx,
			"/Users/cayesha/Desktop/my_so_long/img/hero1.xpm",
			&window->pictures.hero1.width, &window->pictures.hero1.height);
	window->pictures.hero2.img = mlx_xpm_file_to_image(window->mlx,
			"/Users/cayesha/Desktop/my_so_long/img/hero2.xpm",
			&window->pictures.hero2.width, &window->pictures.hero2.height);
	window->pictures.hero3.img = mlx_xpm_file_to_image(window->mlx,
			"/Users/cayesha/Desktop/my_so_long/img/hero3.xpm",
			&window->pictures.hero3.width, &window->pictures.hero3.height);
	window->pictures.door_close.img = mlx_xpm_file_to_image(window->mlx,
			"/Users/cayesha/Desktop/my_so_long/img/door_close.xpm",
			&window->pictures.door_close.width,
			&window->pictures.door_close.height);
	window->pictures.door_open.img = mlx_xpm_file_to_image(window->mlx,
			"/Users/cayesha/Desktop/my_so_long/img/door_open.xpm",
			&window->pictures.door_open.width,
			&window->pictures.door_open.height);
	load_picture_part1(window);
}
