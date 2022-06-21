/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drakan <drakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 17:09:19 by drakan            #+#    #+#             */
/*   Updated: 2022/02/28 13:14:59 by drakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ub;

	ub = (unsigned char *) b;
	i = 0;
	while (i < len)
	{
		ub[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	ft_putstr_(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	clear_screen(t_base *c)
{
	int	i;

	i = -1;
	while (c->map.map[++i])
		free(c->map.map[i]);
	if (c->mlxpointer)
	{
		mlx_clear_window(c->mlxpointer, c->winpointer);
		mlx_destroy_window(c->mlxpointer, c->winpointer);
	}
	exit(0);
}
