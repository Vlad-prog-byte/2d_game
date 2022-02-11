/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayesha <cayesha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:31:35 by cayesha           #+#    #+#             */
/*   Updated: 2022/02/11 16:19:47 by cayesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

void	init_map(data_windows *window)
{
	window->map.height = 0;
	window->map.width = 0;
	window->map.collection = 0;
	window->map.start = 0;
	window->map.finish = 0;
}

int	count_heigth(char *str)
{
	int		count;
	char	*s;
	int		fd;

	count = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (0);
	s = get_next_line(fd);
	if (s == NULL)
	{
		close(fd);
		return (0);
	}
	while (s != NULL)
	{
		count++;
		s = get_next_line(fd);
	}
	close(fd);
	return (count);
}

int	full(char *s, data_map *map)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		if (s[i] == 'E')
			map->finish++;
		else if (s[i] == 'P')
			map->start++;
		else if (s[i] == 'C')
			map->collection++;
		else if (s[i] == '0' || s[i] == '1')
		{
			i++;
			continue ;
		}
		else
			return (0);
		i++;
	}
	return (1);
}

int	count_svoistva(data_map map)
{
	if (map.start != 1)
		return (0);
	if (map.finish == 0)
		return (0);
	if (map.collection == 0)
		return (0);
	return (1);
}
