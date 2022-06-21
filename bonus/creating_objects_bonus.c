/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_objects_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drakan <drakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:44:51 by drakan            #+#    #+#             */
/*   Updated: 2022/02/28 20:34:38 by drakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_create(t_base *c)
{
	c->k = -1;
	c->l = -1;
	c->i = 0;
	c->j = 0;
	while (c->map.map[++c->k])
	{
		c->i = 0;
		c->l = -1;
		while (c->map.map[c->k][++c->l] != '\0')
		{
			if (c->map.map[c->k][c->l] == 'E')
			{
				if (c->error.no_coins == 0)
					mlx_put_image_to_window(c->mlxpointer, c->winpointer, \
						c->exit2, c->i, c->j);
				else
					mlx_put_image_to_window(c->mlxpointer, c->winpointer, \
						c->exit, c->i, c->j);
			}
			c->i += 50;
		}
		c->j += 50;
	}
	return (0);
}

int	player_create(t_base *c)
{
	c->k = -1;
	c->l = -1;
	c->i = 0;
	c->j = 0;
	while (c->map.map[++c->k])
	{
		c->i = 0;
		c->l = -1;
		while (c->map.map[c->k][++c->l] != '\0')
		{
			if (c->map.map[c->k][c->l] == 'P')
				mlx_put_image_to_window(c->mlxpointer, c->winpointer, \
					c->player, c->i, c->j);
			c->i += 50;
		}
		c->j += 50;
	}
	return (0);
}

void	create_object_2(t_base *c)
{
	if (c->map.map[c->k][c->l] != '1' && c->map.map[c->k][c->l] != 'G' && \
		c->map.map[c->k][c->l] != 'C' && c->map.map[c->k][c->l] != 'E')
		mlx_put_image_to_window(c->mlxpointer, c->winpointer, \
			c->floor, c->i, c->j);
	else if (c->map.map[c->k][c->l] == '1')
		mlx_put_image_to_window(c->mlxpointer, c->winpointer, \
			c->wall, c->i, c->j);
	else if (c->map.map[c->k][c->l] == 'P')
		mlx_put_image_to_window(c->mlxpointer, c->winpointer, \
			c->floor, c->i, c->j);
	else if (c->map.map[c->k][c->l] == 'C')
	{
		mlx_put_image_to_window(c->mlxpointer, c->winpointer, \
			c->floor, c->i, c->j);
		mlx_put_image_to_window(c->mlxpointer, c->winpointer, \
			c->coin, c->i, c->j);
	}
	else if (c->map.map[c->k][c->l] == 'G')
	{
		mlx_put_image_to_window(c->mlxpointer, c->winpointer, \
			c->floor, c->i, c->j);
		mlx_put_image_to_window(c->mlxpointer, c->winpointer, \
			c->enemy, c->i, c->j);
	}
}

void	create_object(t_base *c)
{
	c->k = -1;
	c->l = -1;
	c->i = 0;
	c->j = 0;
	while (c->map.map[++c->k])
	{
		c->i = 0;
		c->l = -1;
		while (c->map.map[c->k][++c->l] != '\0')
		{
			create_object_2(c);
			c->i += 50;
		}
		c->j += 50;
	}
}

int	print_xpm(t_base *c)
{
	create_object(c);
	player_create(c);
	exit_create(c);
	return (0);
}
