/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzidani <yzidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:45:17 by yzidani           #+#    #+#             */
/*   Updated: 2025/10/15 18:59:06 by yzidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	content_utils(char **map, t_data *game, int *exit, int *player)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				(*player)++;
			else if (map[i][j] == 'E')
				(*exit)++;
			else if (map[i][j] == 'C')
				game->collectibles++;
			else if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != '\n')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	content_verif(char **map, t_data *game)
{
	int	exit;
	int	player;

	exit = 0;
	player = 0;
	if (!map || !map[0])
		return (0);
	if (!content_utils(map, game, &exit, &player))
		return (0);
	if (player != 1 || exit != 1 || game->collectibles < 1)
		return (0);
	return (1);
}

int	size_map(t_data *game)
{
	int	screen_width;
	int	screen_heitgh;
	int	map_width_px;
	int	map_height_px;

	if (!game || !game->map || !game->map[0] || !game->mlx)
		return (0);
	map_width_px = game->width * TILE_SIZE;
	map_height_px = game->height * TILE_SIZE;
	mlx_get_screen_size(game->mlx, &screen_width, &screen_heitgh);
	if (map_width_px > screen_width || map_height_px > screen_heitgh)
		return (0);
	return (1);
}
