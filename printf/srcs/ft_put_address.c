/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayesha <cayesha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:51:14 by cayesha           #+#    #+#             */
/*   Updated: 2021/11/19 14:55:12 by cayesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/ft_printf.h"

static char	translate_p(unsigned int number)
{
	if (number < 10)
		return ('0' + number);
	else if (number == 10)
		return ('a');
	else if (number == 11)
		return ('b');
	else if (number == 12)
		return ('c');
	else if (number == 13)
		return ('d');
	else if (number == 14)
		return ('e');
	else
		return ('f');
}

static void	write_number_p(unsigned long number, int *sum)
{
	char	symbol;

	if (number == 0)
		return ;
	else
	{
		write_number_p(number / 16, sum);
		symbol = translate_p(number % 16);
		*sum += write(1, &symbol, 1);
	}
}

void	ft_put_address(unsigned long number, int *sum)
{
	*sum += write(1, "0x", 2);
	if (number == 0)
		*sum += write(1, "0", 1);
	else
		write_number_p(number, sum);
}
