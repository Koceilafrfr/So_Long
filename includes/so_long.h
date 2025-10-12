/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzidani <yzidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:35:33 by yzidani           #+#    #+#             */
/*   Updated: 2025/10/12 18:06:05 by yzidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# define TILE_SIZE 64

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
	int		height;
}	t_data;

//parsing

void	parsing(char **map, char *filename, t_data game);
int		size_map(t_data game);
int		content_verif(char **map, t_data game);
int		is_doable(char **map);
char	**get_map(char *filename);

//setup

void	exit_pos(t_data *game);
void	load_img(t_data *game);

#endif