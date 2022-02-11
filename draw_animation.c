/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayesha <cayesha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:06:03 by cayesha           #+#    #+#             */
/*   Updated: 2022/02/11 15:09:13 by cayesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	draw_pizza2(data_windows *window)
{
	int	i;
	int	j;

	i = 0;
	while (i < window->row)
	{
		j = 0;
		while (j < window->column)
		{
			if (window->game[i][j] == 'C')
				mlx_put_image_to_window(window->mlx,
					window->win, window->pictures.pizza2.img,
					j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	draw_pizza1(data_windows *window)
{
	int	i;
	int	j;

	i = 0;
	while (i < window->row)
	{
		j = 0;
		while (j < window->column)
		{
			if (window->game[i][j] == 'C')
				mlx_put_image_to_window(window->mlx,
					window->win, window->pictures.pizza1.img,
					j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	draw_pizza3(data_windows *window)
{
	int	i;
	int	j;

	i = 0;
	while (i < window->row)
	{
		j = 0;
		while (j < window->column)
		{
			if (window->game[i][j] == 'C')
				mlx_put_image_to_window(window->mlx,
					window->win, window->pictures.pizza3.img,
					j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	draw_hero1(data_windows *window)
{
	int	i;
	int	j;

	i = 0;
	while (i < window->row)
	{
		j = 0;
		while (j < window->column)
		{
			if (window->game[i][j] == 'P')
				mlx_put_image_to_window(window->mlx,
					window->win, window->pictures.hero1.img,
					j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	draw_hero2(data_windows *window)
{
	int	i;
	int	j;

	i = 0;
	while (i < window->row)
	{
		j = 0;
		while (j < window->column)
		{
			if (window->game[i][j] == 'P')
				mlx_put_image_to_window(window->mlx,
					window->win, window->pictures.hero2.img,
					j * 50, i * 50);
			j++;
		}
		i++;
	}
}
