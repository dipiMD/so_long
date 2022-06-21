/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drakan <drakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 17:10:58 by drakan            #+#    #+#             */
/*   Updated: 2022/02/28 20:12:03 by drakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "get_next_line/get_next_line.h"

typedef struct s_error
{
	int				no_walls;
	int				no_player;
	int				no_coins;
	int				no_exit;
	int				no_open_file;
	int				invalid_character;
	int				error_map;
}				t_error;

typedef struct s_map
{
	char			**map;
	int				width;
	int				width_wall;
	int				height;
	int				count_coin;
	int				count_player;
	int				count_rows;
	int				count_exit;
	int				len;
}				t_map;

typedef struct s_base
{
	struct s_map	map;
	struct s_error	error;
	char			*file_name;
	void			*mlxpointer;
	void			*winpointer;
	void			*exit;
	void			*floor;
	void			*wall;
	void			*player;
	void			*exit2;
	void			*player2;
	void			*coin;
	void			*enemy;
	int				moves;
	int				player_win;
	int				fd;
	int				i;
	int				j;
	int				k;
	int				l;
}				t_base;

void	ft_putstr_(char *str);
void	*ft_memset(void *b, int c, size_t length);
void	check_valid_map(t_base *c);
void	check_wall(t_base *c);
void	create_map(t_base *c, char **argv);
void	init_map_and_error(t_base *c);
void	check_entity(t_base *c);
char	*get_next_line(int fd);
void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
void	*mlx_init(void);
int		mlx_loop(void *mlx_ptr);
int		print_xpm(t_base *c);
int		button_hook(int key, t_base *c);
int		clear_screen(t_base *c);
void	left_move(t_base *c);
void	right_move(t_base *c);
void	xpm_image_read(t_base *c);
void	win_condition(int i, int j, t_base *c);
void	win_condition_right(int i, int j, t_base *c);
void	win_condition_left(int i, int j, t_base *c);
void	win_condition_up(int i, int j, t_base *c);
void	win_condition_down(int i, int j, t_base *c);
char	*ft_itoa(int n);

#endif