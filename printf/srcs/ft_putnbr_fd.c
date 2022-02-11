/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayesha <cayesha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:56:21 by cayesha           #+#    #+#             */
/*   Updated: 2021/11/19 14:56:28 by cayesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/ft_printf.h"

static void	recur(long int n, int *sum)
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

void	ft_putnbr_fd(int n, int *sum)
{
	int			flag;
	long int	new_n;

	flag = 1;
	if (n == 0)
	{
		*sum += write(1, "0", 1);
		return ;
	}
	if (n <= 0)
	{
		*sum += write(1, "-", 1);
		flag = -1;
	}
	new_n = n;
	new_n *= flag;
	recur(new_n, sum);
}
