/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzidani <yzidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 18:52:03 by yzidani           #+#    #+#             */
/*   Updated: 2025/10/15 19:20:58 by yzidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	check_exit(t_data *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] != 'E')
		return (1);
	if (game->collectibles == 0)
	{
		ft_printf("Success\nScore : %d Moves\n", game->moves + 1);
		exit_game(game, 0);
	}
	return (0);
}

static int	handle_move(t_data *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'C')
	{
		game->collectibles--;
		game->map[new_y][new_x] = '0';
	}
	if (!check_exit(game, new_x, new_y))
		return (0);
	if (game->map[game->player_y][game->player_x] == 'E')
		game->map[game->player_y][game->player_x] = 'E';
	else
		game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	ft_printf("Moves : %d\n", game->moves);
	render_map(game);
	return (1);
}

void	move_player(t_data *game, int dy, int dx)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (new_x < 0 || new_y < 0 || new_y >= game->height || new_x >= game->width)
		return ;
	if (game->map[new_y][new_x] == '1')
		return ;
	handle_move(game, new_x, new_y);
}

int	handle_key(int keycode, t_data *game)
{
	if (keycode == KEY_ESC)
		exit_game(game, 1);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_player(game, -1, 0);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(game, 1, 0);
	else if (keycode == KEY_A || keycode == KEY_LARGO)
		move_player(game, 0, -1);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(game, 0, 1);
	return (0);
}
