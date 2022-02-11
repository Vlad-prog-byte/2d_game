/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayesha <cayesha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:53:32 by cayesha           #+#    #+#             */
/*   Updated: 2021/11/19 14:54:22 by cayesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/ft_printf.h"

static void	recur(unsigned long int n, int *sum)
{
	char	c;

	if (n < 10)
	{
		c = n + '0';
		*sum += write(1, &c, 1);
	}
	else
	{
		recur(n / 10, sum);
		recur(n % 10, sum);
	}
}

void	ft_put_unsigned_int(unsigned int n, int *sum)
{
	unsigned long int	new_n;

	if (n == 0)
	{
		*sum += write(1, "0", 1);
		return ;
	}
	new_n = n;
	recur(new_n, sum);
}
