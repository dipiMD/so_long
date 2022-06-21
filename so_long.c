/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drakan <drakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:10:42 by drakan            #+#    #+#             */
/*   Updated: 2022/02/28 13:15:16 by drakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf/ft_printf.h"

void	init_map_and_error(t_base *c)
{
	c->mlxpointer = NULL;
	c->map.width = 0;
	c->fd = 0;
	c->map.width_wall = 0;
	c->map.height = 0;
	c->map.count_coin = 0;
	c->map.count_exit = 0;
	c->map.count_player = 0;
	c->map.count_rows = 0;
	c->map.len = 0;
	c->error.no_coins = 0;
	c->error.no_exit = 0;
	c->error.no_player = 0;
	c->error.no_walls = 0;
	c->error.no_open_file = 0;
	c->error.invalid_character = 0;
	c->error.error_map = 0;
	c->player_win = 0;
	c->i = 0;
	c->moves = 0;
	c->j = 0;
	c->k = 0;
	c->l = 0;
}

int	add_line(t_base *c, char *line)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (!line)
		return (0);
	c->map.width++;
	tmp = (char **)malloc(sizeof(char *) * (c->map.width + 1));
	tmp[c->map.width] = NULL;
	while (i < c->map.width - 1)
	{
		tmp[i] = c->map.map[i];
		i++;
	}
	tmp[i] = line;
	if (c->map.map)
		free(c->map.map);
	c->map.map = tmp;
	return (1);
}

void	create_map(t_base *c, char **argv)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	c->fd = open(argv[1], O_RDONLY);
	if (c->fd < 0)
	{
		c->error.no_open_file = 1;
		return ;
	}
	while (1)
	{
		tmp = get_next_line(c->fd);
		if (!add_line(c, tmp))
			break ;
	}
	close (c->fd);
	c->map.width_wall = ft_strlen(&c->map.map[0][i++]);
}

void	check_entity(t_base *c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (c->map.map[i][j] != '\0')
	{
		if (c->map.map[i][j] != '0' && c->map.map[i][j] != '1' &&
			c->map.map[i][j] != 'C' && c->map.map[i][j] != 'E' &&
				c->map.map[i][j] != 'P' && c->map.map[i][j] != '\n')
					c->error.invalid_character++;
		if (c->map.map[i][j] == 'C')
			c->error.no_coins++;
		if (c->map.map[i][j] == 'P')
			c->error.no_player++;
		if (c->map.map[i][j] == 'E')
			c->error.no_exit++;
		j++;
		if (c->map.map[i][j] == '\n')
		{
			i++;
			j = 0;
		}
	}
}

int	main(int argc, char *argv[])
{
	t_base	c;

	if (argc != 2)
	{
		ft_putstr("Add one arguments\n");
		return (0);
	}
	ft_memset(&c, 0, sizeof(t_base));
	c.file_name = argv[1];
	init_map_and_error(&c);
	create_map(&c, argv);
	check_valid_map(&c);
	if (c.error.error_map > 0)
		return (0);
	c.mlxpointer = mlx_init();
	c.winpointer = mlx_new_window(c.mlxpointer, ((c.map.width_wall - 1) * 50), \
		(c.map.count_rows * 50), "Half-Life 3");
	xpm_image_read(&c);
	mlx_loop_hook(c.mlxpointer, print_xpm, (void *)&c);
	mlx_hook(c.winpointer, 17, 0, clear_screen, (void *)&c);
	mlx_hook(c.winpointer, 2, 0, button_hook, (void *)&c);
	mlx_loop(c.mlxpointer);
}
