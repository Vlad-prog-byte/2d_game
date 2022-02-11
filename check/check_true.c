/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_true.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayesha <cayesha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:06:45 by cayesha           #+#    #+#             */
/*   Updated: 2022/02/11 17:16:19 by cayesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

int	check_first(int *fd, data_windows *window, char *str)
{
	char	*s;
	int		i;

	i = 0;
	window->map.height = count_heigth(str);
	(*fd) = open(str, O_RDONLY);
	if (fd < 0)
		return (0);
	s = get_next_line(*fd);
	if (s == NULL)
		return (0);
	window->map.width = ft_strlen(s);
	if (window->map.width < 3 || --(window->map.height) < 1)
		return (0);
	while (s[i] != '\0' && s[i] != '\n')
	{
		if (s[i] != '1')
		{
			free(s);
			return (0);
		}
		i++;
	}
	free(s);
	return (1);
}

int	check_second(data_windows *window, int fd)
{
	char	*s;
	int		len;

	len = 0;
	while ((window->map.height)-- > 1)
	{
		s = get_next_line(fd);
		if (s == NULL)
			return (0);
		len = ft_strlen(s);
		if (len < 3 || len != window->map.width)
		{
			free(s);
			return (0);
		}
		if (s[0] != '1' || s[len - 2] != '1' || full(s, &(window->map)) == 0)
		{
			free(s);
			return (0);
		}
		free(s);
	}
	if (count_svoistva(window->map) == 0)
		return (0);
	return (1);
}

int	check_third(int fd, data_windows *window)
{
	char	*s;
	int		i;

	s = get_next_line(fd);
	if (ft_strlen(s) != window->map.width - 1)
		return (0);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		if (s[i++] != '1')
			return (0);
	return (1);
}

int	check_map(char *str, data_windows *window)
{
	int	fd;
	int	i;

	i = 0;
	init_map(window);
	if (check_first(&fd, window, str) == 0)
		return (0);
	if (check_second(window, fd) == 0)
		return (0);
	if (check_third(fd, window) == 0)
	{
		close(fd);
		return (0);
	}
	return (1);
}

int	check(int count, char **strs, data_windows *window)
{
	int	length;

	length = ft_strlen(strs[1]);
	if (count != 2)
		return (0);
	if (ft_strlen(strs[1]) < 5)
		return (0);
	if (strs[1][length - 1] != 'r' || strs[1][length - 2] != 'e' ||
	strs[1][length - 3] != 'b' || strs[1][length - 4] != '.')
		return (0);
	if (check_map(strs[1], window) == 0)
		return (0);
	return (1);
}