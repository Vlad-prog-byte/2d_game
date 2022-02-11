/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pictures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayesha <cayesha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:13:31 by cayesha           #+#    #+#             */
/*   Updated: 2022/02/11 15:13:37 by cayesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"./so_long.h"

void	draw_wall(data_windows *window, int i, int j)
{
	mlx_put_image_to_window(window->mlx, window->win,
		window->pictures.wall.img, j * 50, i * 50);
}

void	draw_pizza(data_windows *window, int i, int j)
{
	mlx_put_image_to_window(window->mlx, window->win,
		window->pictures.pizza1.img, j * 50, i * 50);
}

void	draw_exit(data_windows *window, int i, int j)
{
	mlx_put_image_to_window(window->mlx, window->win,
		window->pictures.door_close.img, j * 50, i * 50);
}

void	draw_player(data_windows *window, int i, int j)
{
	window->bot.x = i;
	window->bot.y = j;
	mlx_put_image_to_window(window->mlx, window->win,
		window->pictures.hero3.img, j * 50, i * 50);
}

void	draw_ground(data_windows *window, int i, int j)
{
	mlx_put_image_to_window(window->mlx, window->win,
		window->pictures.ground.img, j * 50, i * 50);
}
