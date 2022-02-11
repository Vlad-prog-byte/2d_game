/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayesha <cayesha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:15:36 by cayesha           #+#    #+#             */
/*   Updated: 2022/02/11 16:05:25 by cayesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"./so_long.h"

void	move_up(data_windows *window)
{
	if (window->game[window->bot.x - 1][window->bot.y] == '0')
	{
		window->game[window->bot.x][window->bot.y] = '0';
		draw_ground(window, window->bot.x, window->bot.y);
		(window->bot.x)--;
		window->game[window->bot.x][window->bot.y] = 'P';
		draw_player(window, window->bot.x, window->bot.y);
		draw_score(window);
	}
	else if (window->game[window->bot.x - 1][window->bot.y] == 'C')
	{
		window->game[window->bot.x][window->bot.y] = '0';
		draw_ground(window, window->bot.x, window->bot.y);
		(window->bot.x)--;
		window->game[window->bot.x][window->bot.y] = 'P';
		draw_player(window, window->bot.x, window->bot.y);
		window->map.collection--;
		draw_score(window);
		if (window->map.collection == 0)
			find_exit(window);
	}
	else if (window->game[window->bot.x - 1][window->bot.y] == 'E'
		&& window->map.collection == 0)
		exit(0);
}

void	move_left(data_windows *window)
{
	if (window->game[window->bot.x][window->bot.y - 1] == '0')
	{
		window->game[window->bot.x][window->bot.y] = '0';
		draw_ground(window, window->bot.x, window->bot.y);
		(window->bot.y)--;
		window->game[window->bot.x][window->bot.y] = 'P';
		draw_player(window, window->bot.x, window->bot.y);
		draw_score(window);
	}
	else if (window->game[window->bot.x][window->bot.y - 1] == 'C')
	{
		window->game[window->bot.x][window->bot.y] = '0';
		draw_ground(window, window->bot.x, window->bot.y);
		(window->bot.y)--;
		window->game[window->bot.x][window->bot.y] = 'P';
		draw_player(window, window->bot.x, window->bot.y);
		window->map.collection--;
		draw_score(window);
		if (window->map.collection == 0)
			find_exit(window);
	}
	else if (window->game[window->bot.x][window->bot.y - 1] == 'E'
		&& window->map.collection == 0)
		exit(0);
}

void	move_down(data_windows *window)
{
	if (window->game[window->bot.x + 1][window->bot.y] == '0')
	{
		window->game[window->bot.x][window->bot.y] = '0';
		draw_ground(window, window->bot.x, window->bot.y);
		(window->bot.x)++;
		window->game[window->bot.x][window->bot.y] = 'P';
		draw_player(window, window->bot.x, window->bot.y);
		draw_score(window);
	}
	else if (window->game[window->bot.x + 1][window->bot.y] == 'C')
	{
		window->game[window->bot.x][window->bot.y] = '0';
		draw_ground(window, window->bot.x, window->bot.y);
		(window->bot.x)++;
		window->game[window->bot.x][window->bot.y] = 'P';
		draw_player(window, window->bot.x, window->bot.y);
		window->map.collection--;
		draw_score(window);
		if (window->map.collection == 0)
			find_exit(window);
	}
	else if (window->game[window->bot.x + 1][window->bot.y] == 'E'
		&& window->map.collection == 0)
		exit(0);
}

void	move_right(data_windows *window)
{
	if (window->game[window->bot.x][window->bot.y + 1] == '0')
	{
		window->game[window->bot.x][window->bot.y] = '0';
		draw_ground(window, window->bot.x, window->bot.y);
		(window->bot.y)++;
		window->game[window->bot.x][window->bot.y] = 'P';
		draw_player(window, window->bot.x, window->bot.y);
		draw_score(window);
	}
	else if (window->game[window->bot.x][window->bot.y + 1] == 'C')
	{
		window->game[window->bot.x][window->bot.y] = '0';
		draw_ground(window, window->bot.x, window->bot.y);
		(window->bot.y)++;
		window->game[window->bot.x][window->bot.y] = 'P';
		draw_player(window, window->bot.x, window->bot.y);
		window->map.collection--;
		draw_score(window);
		if (window->map.collection == 0)
			find_exit(window);
	}
	else if (window->game[window->bot.x][window->bot.y + 1] == 'E'
		&& window->map.collection == 0)
		exit(0);
}

int	key_hook(int key_code, data_windows *window)
{
	if (key_code == 53)
		exit(0);
	else if (key_code == W)
		move_up(window);
	else if (key_code == S)
		move_down(window);
	else if (key_code == A)
		move_left(window);
	else if (key_code == D)
		move_right(window);
	return (0);
}
