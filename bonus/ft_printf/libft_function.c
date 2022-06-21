/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drakan <drakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:07:18 by drakan            #+#    #+#             */
/*   Updated: 2022/02/28 13:13:01 by drakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int	num_print;

	num_print = 0;
	if (nb == -2147483648)
	{
		num_print += ft_putchar('-');
		num_print += ft_putchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		num_print += ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		num_print += ft_putnbr(nb / 10);
		num_print += ft_putnbr(nb % 10);
	}
	else
		num_print += ft_putchar(nb + 48);
	return (num_print);
}

int	ft_unsigned_putnbr(unsigned int nb)
{
	unsigned int	num;
	unsigned int	num_print;

	num_print = 0;
	num = nb;
	if (num >= 10)
		num_print += ft_unsigned_putnbr(num / 10);
	num_print += ft_putchar((num % 10 + 48));
	return (num_print);
}
