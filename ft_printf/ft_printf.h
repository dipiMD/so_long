/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drakan <drakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:54:25 by drakan            #+#    #+#             */
/*   Updated: 2022/02/28 13:13:12 by drakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_putnbr(int nb);
char	*ft_strchr(const char *str, int c);
int		ft_16convert(unsigned long long int nb, char *notation);
int		ft_pointer(void *str);
int		ft_unsigned_putnbr(unsigned int nb);
int		ft_check_symb(char c, va_list ap);

#endif
