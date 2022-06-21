/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drakan <drakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:32:26 by drakan            #+#    #+#             */
/*   Updated: 2022/02/28 20:34:23 by drakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_name(char *file, t_base *c)
{
	size_t	i;

	i = ft_strlen(file);
	if (file[i - 1] == 'r')
		if (file[i - 2] == 'e')
			if (file[i - 3] == 'b')
				if (file[i - 4] == '.')
					return (1);
	c->error.error_map++;
	ft_putstr_("invalid file extension");
	return (0);
}

int	check_count_rows_and_valid_name(char *file, t_base *c)
{
	int		fd;
	int		count;
	char	symbol;

	count = 1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	valid_name(file, c);
	while (read(fd, &symbol, 1))
	{
		if (symbol == '\n')
			count++;
	}
	close(fd);
	return (count);
}

void	check_wall(t_base *c)
{
	c->i = 0;
	c->j = 0;
	while (c->map.map[c->i][c->j] != '\0')
	{
		if ((c->map.map[c->i][c->j] != '1' && (c->map.count_rows - 1) == c->i) \
			|| ((c->map.width_wall - 2) < c->j && \
				(c->map.count_rows - 1) == c->i))
			c->error.no_walls++;
		if ((c->map.map[c->i][c->j] != '1' && c->i == 0) || \
			(c->map.map[c->i][c->j] != '1' && c->j == 0))
				c->error.no_walls++;
		c->j++;
		if (c->map.map[c->i][c->j] == '\0' && c->map.width_wall - 1 != c->j)
			c->error.no_walls++;
		if (c->map.map[c->i][c->j] == '\n')
		{
			if (c->map.width_wall - 1 != c->j && \
				c->i != (c->map.count_rows - 1))
				c->error.no_walls++;
			if (c->map.map[c->i][c->j - 1] != '1')
				c->error.no_walls++;
			c->i++;
			c->j = 0;
		}
	}
}

void	error_write(t_base *c)
{
	if (c->error.no_coins < 1)
	{
		ft_putstr_("Not enough collectibles in the map \n");
	}
	if (c->error.no_player != 1)
	{
		ft_putstr_("Incorrect number of players \n");
	}
	if (c->error.no_exit != 1)
	{
		ft_putstr_("Incorrect number of outputs \n");
	}
	if (c->error.no_open_file > 0)
	{
		ft_putstr_("The provided file cannot be opened \n");
	}
	if (c->error.no_walls > 0)
	{
		ft_putstr_("The wall is not built correctly \n");
	}
	if (c->error.invalid_character > 0)
	{
		ft_putstr_("Wrong symbol on the map \n");
	}
}

void	check_valid_map(t_base *c)
{
	c->map.count_rows = check_count_rows_and_valid_name(c->file_name, c);
	check_wall(c);
	check_entity(c);
	error_write(c);
	if (c->error.no_coins < 1 || c->error.no_player != 1 || \
		c->error.no_exit != 1 || c->error.no_open_file > 0 || \
			c->error.no_walls > 0 || c->error.invalid_character > 0)
					c->error.error_map++;
}
