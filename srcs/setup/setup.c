/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzidani <yzidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 20:03:22 by yzidani           #+#    #+#             */
/*   Updated: 2025/10/11 20:09:25 by yzidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init(t_game *game)
{
	game->map = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->player_img = NULL;
	game->wall_img = NULL;
	game->floor_img = NULL;
	game->collectible_img = NULL;
	game->player_x = 0;
	game->player_y = 0;
	game->exit_x = 0;
	game->exit_y = 0;
	game->collectibles = 0;
	game->moves = 0;
}
