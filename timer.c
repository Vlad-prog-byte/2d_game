/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayesha <cayesha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:02:38 by cayesha           #+#    #+#             */
/*   Updated: 2022/02/11 15:08:01 by cayesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	draw_hero3(data_windows *window)
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
					window->win, window->pictures.hero3.img,
					j * 50, i * 50);
			j++;
		}
		i++;
	}
}

int	timer(data_windows *window)
{
	static int	time;

	if (time % 90 < 30)
	{
		draw_pizza2(window);
		draw_hero2(window);
	}
	else if (time % 90 < 60)
	{
		draw_pizza3(window);
		draw_hero1(window);
	}
	else
	{
		draw_pizza1(window);
		draw_hero3(window);
	}
	time++;
	if (time == 91)
		time = 0;
	return (0);
}
