/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzidani <yzidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:35:33 by yzidani           #+#    #+#             */
/*   Updated: 2025/10/16 14:58:41 by yzidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# define TILE_SIZE 64

# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LARGO 65361
# define KEY_RIGHT 65363
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100

# include <stdlib.h>
# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include "../gnl/get_next_line.h"
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <mlx.h>

typedef struct s_data {
	char	**map;
	void	*win;
	void	*mlx;
	void	*player_img;
	void	*wall_img;
	void	*floor_img;
	void	*exit_img;
	void	*collectible_img;

	int		moves;
	int		collectibles;
	int		height;
	int		player_x;
	int		player_y;
	int		width;
	int		exit_x;
	int		exit_y;
}	t_data;

//parsing

int		parsing(char **map, char *filename, t_data *game);
int		size_map(t_data *game);
int		content_verif(char **map, t_data *game);
int		is_doable(char **map, t_data *game);
int		first_last_row(char *row);
char	**get_map(char *filename);
void	ft_flood_fill(char **map, int y, int x, int include_exit);

//setup

void	init(t_data *game);
int		exit_cross(t_data *game);
void	init_game(t_data *game, char *filename);
void	exit_game(t_data *game, int status);
void	exit_pos(t_data *game);
void	load_img(t_data *game);
void	render_map(t_data *game);

//move

void	move_player(t_data *game, int dy, int dx);
int		handle_key(int keycode, t_data *game);

#endif