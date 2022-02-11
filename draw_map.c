/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayesha <cayesha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:11:37 by cayesha           #+#    #+#             */
/*   Updated: 2022/02/11 15:14:26 by cayesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(data_windows *window)
{
	int	i;
	int	j;

	i = 0;
	while (i < window->row)
	{
		j = 0;
		while (j < window->column)
		{
			if (window->game[i][j] == '1')
				draw_wall(window, i, j);
			else if (window->game[i][j] == 'C')
				draw_pizza(window, i, j);
			else if (window->game[i][j] == 'E')
				draw_exit(window, i, j);
			else if (window->game[i][j] == 'P')
				draw_player(window, i, j);
			else
				draw_ground(window, i, j);
			j++;
		}
		i++;
	}
}
