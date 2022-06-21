/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_condition_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drakan <drakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:27:12 by drakan            #+#    #+#             */
/*   Updated: 2022/02/28 20:35:22 by drakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_condition_down(int i, int j, t_base *c)
{
	if (c->error.no_coins == 0 && c->map.map[i - 1][j] == 'E')
	{
		ft_putstr_("🔥YOU WIN🔥\n");
		clear_screen(c);
	}
}

void	win_condition_up(int i, int j, t_base *c)
{
	if (c->error.no_coins == 0 && c->map.map[i + 1][j] == 'E')
	{
		ft_putstr_("🔥YOU WIN🔥\n");
		clear_screen(c);
	}
}

void	win_condition_left(int i, int j, t_base *c)
{
	if (c->error.no_coins == 0 && c->map.map[i][j - 1] == 'E')
	{
		ft_putstr_("🔥YOU WIN🔥\n");
		clear_screen(c);
	}
}

void	win_condition_right(int i, int j, t_base *c)
{
	if (c->error.no_coins == 0 && c->map.map[i][j + 1] == 'E')
	{
		ft_putstr_("🔥YOU WIN🔥\n");
		clear_screen(c);
	}
}
