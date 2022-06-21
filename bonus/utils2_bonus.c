/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drakan <drakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:51:08 by drakan            #+#    #+#             */
/*   Updated: 2022/02/28 20:35:32 by drakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_num(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static char	*norm1(char *str, int i, int j)
{
	if (i < 0)
		i *= -1;
	while (i > 0)
	{
		str[j] = i % 10 + '0';
		i /= 10;
		j--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		k;
	char	*s1;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	k = n;
	i = count_num(k);
	if (n == 0)
		s1 = (char *)malloc(sizeof(char) * 2);
	else
		s1 = (char *)malloc(sizeof(char) * i + 1);
	if (s1 == NULL)
		return (NULL);
	s1[i--] = '\0';
	if (n == 0)
	{
		s1[0] = '0';
		return (s1);
	}
	if (n < 0)
		s1[0] = '-';
	norm1(s1, n, i);
	return (s1);
}
