/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzidani <yzidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 16:22:38 by yzidani           #+#    #+#             */
/*   Updated: 2025/10/13 17:40:36 by yzidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	exit_cross(t_data *game)
{
	exit_game(game, 0);
	return (0);
}

static void	render_tile(t_data *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->floor_img, x * 64, y * 64);
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall_img, x * 64, y * 64);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->collectible_img, x * 64, y * 64);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit_img, x * 64, y * 64);
	if (x == game->player_x && y == game->player_y)
		mlx_put_image_to_window(game->mlx, game->win,
			game->player_img, x * 64, y * 64);
}

void	render_map(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->height)
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
}

void	load_img(t_data *game)
{
	int	img_width;
	int	img_height;

	ft_printf("test\n");
	game->player_img = mlx_xpm_file_to_image(game->mlx,
			"sprites/player.xpm", &img_width, &img_height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx,
			"sprites/exit.xpm", &img_width, &img_height);
	game->wall_img = mlx_xpm_file_to_image(game->mlx,
			"sprites/wall.xpm", &img_width, &img_height);
	game->floor_img = mlx_xpm_file_to_image(game->mlx,
			"sprites/floor.xpm", &img_width, &img_height);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx,
			"sprites/collectible.xpm", &img_width, &img_height);
	if (!game->player_img || !game->exit_img || !game->wall_img
		|| !game->floor_img || !game->collectible_img)
	{
		ft_printf("Failed to load images\n");
		exit_game(game, 1);
	}
}

void	exit_pos(t_data *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'E')
			{
				game->exit_x = x;
				game->exit_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
