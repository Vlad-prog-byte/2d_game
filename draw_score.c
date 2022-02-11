/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_score.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayesha <cayesha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:27:54 by cayesha           #+#    #+#             */
/*   Updated: 2022/02/11 17:27:16 by cayesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"./so_long.h"

static void	recur(long int n)
{
	char	c;

	if (n < 10)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else
	{
		recur(n / 10);
		recur(n % 10);
	}
}

void	ft_putnbr_fd(int n)
{
	int			flag;
	long int	new_n;

	flag = 1;
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (n <= 0)
	{
		write(1, "-", 1);
		flag = -1;
	}
	new_n = n;
	new_n *= flag;
	recur(new_n);
}

void	find_exit(data_windows *windows)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < windows->row)
	{
		j = 0;
		while (j < windows->column)
		{
			if (windows->game[i][j] == 'E')
				mlx_put_image_to_window(windows->mlx,
					windows->win,
					windows->pictures.door_open.img, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	draw_score(data_windows *window)
{
	mlx_put_image_to_window(window->mlx, window->win, window->pictures.wall.img, 0, 0);
	(window->bot.score)++;
	char	*count;
	count = ft_itoa(window->bot.score);
	mlx_string_put(window->mlx, window->win, 0, 0, 0x00FF0000, count);
	free(count);
	ft_printf("%d\n", window->bot.score);
}