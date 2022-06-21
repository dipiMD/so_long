/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_and_right_move.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drakan <drakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:43:35 by drakan            #+#    #+#             */
/*   Updated: 2022/02/28 13:13:39 by drakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf/ft_printf.h"

void	right_move_search_environment(int i, int j, t_base *c)
{
	if (c->map.map[i][j + 1] != '1')
	{
		if (c->map.map[i][j + 1] == 'C')
		{
			c->moves++;
			c->error.no_coins--;
			c->map.map[i][j + 1] = 'P';
			c->map.map[i][j] = '0';
		}
		if (c->map.map[i][j + 1] == '0')
		{
			c->moves++;
			c->map.map[i][j + 1] = 'P';
			c->map.map[i][j] = '0';
		}
	}
}

void	right_move(t_base *c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (c->map.map[i][j] != '\0')
	{
		if (c->map.map[i][j] == 'P')
		{
			mlx_clear_window(c->mlxpointer, c->winpointer);
			print_xpm(c);
			break ;
		}
		j++;
		if (c->map.map[i][j] == '\n')
		{
			i++;
			j = 0;
		}
	}
	right_move_search_environment(i, j, c);
	win_condition_right(i, j, c);
	ft_printf("Count move -> %d\n", c->moves);
}

void	left_move_search_environment(int i, int j, t_base *c)
{
	if (c->map.map[i][j - 1] != '1')
	{
		if (c->map.map[i][j - 1] == 'C')
		{
			c->moves++;
			c->error.no_coins--;
			c->map.map[i][j - 1] = 'P';
			c->map.map[i][j] = '0';
		}
		if (c->map.map[i][j - 1] == '0')
		{
			c->moves++;
			c->map.map[i][j - 1] = 'P';
			c->map.map[i][j] = '0';
		}
	}
}

void	left_move(t_base *c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (c->map.map[i][j] != '\0')
	{
		if (c->map.map[i][j] == 'P')
		{
			mlx_clear_window(c->mlxpointer, c->winpointer);
			print_xpm(c);
			break ;
		}
		j++;
		if (c->map.map[i][j] == '\n')
		{
			i++;
			j = 0;
		}
	}
	left_move_search_environment(i, j, c);
	win_condition_left(i, j, c);
	ft_printf("Count move -> %d\n", c->moves);
}

void	xpm_image_read(t_base *c)
{
	int	l;
	int	k;

	c->exit = mlx_xpm_file_to_image(c->mlxpointer, \
		"xpm_image/door.XPM", &l, &k);
	c->floor = mlx_xpm_file_to_image(c->mlxpointer, \
		"xpm_image/floor2.XPM", &l, &k);
	c->wall = mlx_xpm_file_to_image(c->mlxpointer, \
		"xpm_image/wall.XPM", &l, &k);
	c->player = mlx_xpm_file_to_image(c->mlxpointer, \
		"xpm_image/player.XPM", &l, &k);
	c->coin = mlx_xpm_file_to_image(c->mlxpointer, \
		"xpm_image/coin.XPM", &l, &k);
	c->exit2 = mlx_xpm_file_to_image(c->mlxpointer, \
		"xpm_image/door2.XPM", &l, &k);
}
