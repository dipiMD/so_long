/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drakan <drakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:00:32 by drakan            #+#    #+#             */
/*   Updated: 2022/02/28 13:13:20 by drakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_16convert(unsigned long long int nb, char *notation)
{
	int	i;

	i = 0;
	if (nb >= 16)
	{
		i += ft_16convert(nb / 16, notation);
		nb = nb % 16;
		if (nb <= 9)
			i += ft_putchar(nb + '0');
		else
			i += ft_putchar((char)notation[nb]);
	}
	else
	{
		nb = nb % 16;
		if (nb <= 9)
			i += ft_putchar(nb + '0');
		else
			i += ft_putchar((char)notation[nb]);
	}
	return (i);
}

int	ft_pointer(void *str)
{
	int	i;

	i = 0;
	i += write (1, "0x", 2);
	i += ft_16convert((unsigned long long int)str, "0123456789abcdef");
	return (i);
}

int	ft_check_symb(char c, va_list ap)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (c == 'd')
		return (ft_putnbr(va_arg(ap, int)));
	if (c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (c == 'p')
		return (ft_pointer(va_arg(ap, void *)));
	if (c == '%')
		return (ft_putchar(c));
	if (c == 'x')
		return (ft_16convert(va_arg(ap, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_16convert(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	if (c == 'u')
		return (ft_unsigned_putnbr(va_arg(ap, int)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	size_t	j;

	if (!str)
		return (0);
	j = 0;
	i = 0;
	va_start(ap, str);
	while (str[j])
	{
		if (str[j] == '%' && ft_strchr("cdispxXu%", str[j + 1]))
		{
			i += ft_check_symb(str[++j], ap);
			j++;
		}
		else
		{
			i += ft_putchar(str[j]);
			j++;
		}
	}
	va_end (ap);
	return (i);
}
