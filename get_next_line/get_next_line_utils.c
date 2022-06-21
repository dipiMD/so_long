/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drakan <drakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:39:03 by drakan            #+#    #+#             */
/*   Updated: 2022/02/28 19:20:30 by drakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *str1)
{
	int		i;
	char	*arr;

	i = 0;
	if (!str1)
		return (NULL);
	while (str1[i] != '\0')
		i++;
	arr = (char *)malloc((sizeof (*str1) * i + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (str1[i] != '\0')
	{
		arr[i] = str1[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
	{
		return ((char *)str);
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(*s1) * ft_strlen((char *)s1)
			+ ft_strlen((char *)s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
