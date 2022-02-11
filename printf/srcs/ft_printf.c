/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayesha <cayesha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:48:39 by cayesha           #+#    #+#             */
/*   Updated: 2021/11/19 14:54:56 by cayesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/ft_printf.h"

static void	check_str(int i, va_list arg, int *sum, const char *str)
{
	if (str[i] == 'c' )
		ft_putchar_fd((char)va_arg(arg, int), sum);
	else if (str[i] == 'd' || str[i] == 'i')
		ft_putnbr_fd(va_arg(arg, int), sum);
	else if (str[i] == 's')
		ft_putstr_fd((char *)va_arg(arg, void *), sum);
	else if (str[i] == '%')
		*sum += write(1, &str[i], 1);
	else if (str[i] == 'u')
		ft_put_unsigned_int(va_arg(arg, unsigned int), sum);
	else if (str[i] == 'x' || str[i] == 'X')
		ft_put_hexadecimal(va_arg(arg, unsigned int), sum, str[i]);
	else if (str[i] == 'p')
		ft_put_address((unsigned long)va_arg(arg, void *), sum);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		sum;
	va_list	arg;

	va_start(arg, str);
	sum = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
			check_str(++i, arg, &sum, str);
		else
			sum += write(1, &str[i], 1);
		i++;
	}
	va_end(arg);
	return (sum);
}
