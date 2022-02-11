/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayesha <cayesha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:47:23 by cayesha           #+#    #+#             */
/*   Updated: 2021/11/19 13:48:18 by cayesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putnbr_fd(int n, int *sum);
void	ft_putstr_fd(char *s, int *sum);
void	ft_put_unsigned_int(unsigned int n, int *sum);
void	ft_putchar_fd(char c, int *sum);
void	ft_put_hexadecimal(unsigned int number, int *sum, char c);
void	ft_put_address(unsigned long number, int *sum);
int		ft_printf(const char *str, ...);
#endif
