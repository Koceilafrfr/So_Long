/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzidani <yzidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 20:03:22 by yzidani           #+#    #+#             */
/*   Updated: 2025/10/15 20:23:29 by yzidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	start_player_pos(t_data *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	free_textures(t_data *game)
{
	if (game->collectible_img)
		mlx_destroy_image(game->mlx, game->collectible_img);
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->floor_img)
		mlx_destroy_image(game->mlx, game->floor_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

void	exit_game(t_data *game, int status)
{
	int	i;

	if (!game)
		exit(status);
	if (game->map)
	{
		i = 0;
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	free_textures(game);
	free(game);
	exit(status);
}

void	init_game(t_data *game, char *filename)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_game(game, 1);
	game->map = get_map(filename);
	if (!game->map)
	{
		ft_printf("Incorrect map\n");
		exit_game(game, 1);
	}
	game->height = 0;
	while (game->map[game->height])
		game->height++;
	game->width = ft_strlen(game->map[0]);
	game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE,
			game->height * TILE_SIZE, "so_long");
	if (!game->win)
		exit_game(game, 1);
	game->moves = 0;
	start_player_pos(game);
	exit_pos(game);
}

void	init(t_data *game)
{
	game->map = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->player_img = NULL;
	game->wall_img = NULL;
	game->floor_img = NULL;
	game->exit_img = NULL;
	game->collectible_img = NULL;
	game->player_x = 0;
	game->player_y = 0;
	game->exit_x = 0;
	game->exit_y = 0;
	game->collectibles = 0;
	game->moves = 0;
}
