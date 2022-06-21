/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drakan <drakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:44:51 by drakan            #+#    #+#             */
/*   Updated: 2022/02/28 13:13:33 by drakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf/ft_printf.h"

void	down_move_search_environment(int i, int j, t_base *c)
{
	if (c->map.map[i - 1][j] != '1')
	{
		if (c->map.map[i - 1][j] == 'C')
		{
			c->moves++;
			c->error.no_coins--;
			c->map.map[i - 1][j] = 'P';
			c->map.map[i][j] = '0';
		}
		if (c->map.map[i - 1][j] == '0')
		{
			c->moves++;
			c->map.map[i - 1][j] = 'P';
			c->map.map[i][j] = '0';
		}
	}
}

void	down_move(t_base *c)
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
	down_move_search_environment(i, j, c);
	win_condition_down(i, j, c);
	ft_printf("Count move -> %d\n", c->moves);
}

void	up_move_search_environment(int i, int j, t_base *c)
{
	if (c->map.map[i + 1][j] != '1')
	{
		if (c->map.map[i + 1][j] == 'C')
		{
			c->moves++;
			c->error.no_coins--;
			c->map.map[i + 1][j] = 'P';
			c->map.map[i][j] = '0';
		}
		if (c->map.map[i + 1][j] == '0')
		{
			c->moves++;
			c->map.map[i + 1][j] = 'P';
			c->map.map[i][j] = '0';
		}
	}
}

void	up_move(t_base *c)
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
	up_move_search_environment(i, j, c);
	win_condition_up(i, j, c);
	ft_printf("Count move -> %d\n", c->moves);
}

int	button_hook(int key, t_base *c)
{
	if (key == 2)
		right_move(c);
	if (key == 0)
		left_move(c);
	if (key == 13)
		down_move(c);
	if (key == 1)
		up_move(c);
	if (key == 53)
		clear_screen(c);
	return (key);
}
