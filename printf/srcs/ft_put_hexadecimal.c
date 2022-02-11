/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexadecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayesha <cayesha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:48:17 by cayesha           #+#    #+#             */
/*   Updated: 2021/11/19 14:55:28 by cayesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/ft_printf.h"

static char	translate(unsigned int number, int flag)
{
	if (number < 10)
		return ('0' + number);
	else if (number == 10)
		return ('A' + flag);
	else if (number == 11)
		return ('B' + flag);
	else if (number == 12)
		return ('C' + flag);
	else if (number == 13)
		return ('D' + flag);
	else if (number == 14)
		return ('E' + flag);
	else
		return ('F' + flag);
}

static void	write_number(unsigned int number, int *sum, int flag)
{
	char	symbol;

	if (number == 0)
		return ;
	else
	{
		write_number(number / 16, sum, flag);
		symbol = translate(number % 16, flag);
		*sum += write(1, &symbol, 1);
	}
}

void	ft_put_hexadecimal(unsigned int number, int *sum, char c)
{
	int	flag;

	if (c == 'x')
		flag = 32;
	else
		flag = 0;
	if (number == 0)
		*sum += write(1, "0", 1);
	write_number(number, sum, flag);
}
