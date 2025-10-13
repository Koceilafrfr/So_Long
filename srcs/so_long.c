/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzidani <yzidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:36:40 by yzidani           #+#    #+#             */
/*   Updated: 2025/10/13 17:38:05 by yzidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_data	*game;

	game = malloc(sizeof(t_data));

	if (ac != 2)
	{
		ft_printf("Check args : ./so_long .ber");
		return (0);
	}
	init(game);
	init_game(game, av[1]);
	if (!game->map)
	{
		ft_printf("Error map\n");
		exit_game(game, 1);
	}
	if (!parsing(game->map, av[1], game))
		exit_game(game, 1);
	ft_printf("test\n");
	load_img(game);
	render_map(game);
	mlx_key_hook(game->win, handle_key, game);
	mlx_hook(game->win, 17, 0, exit_cross, game);
	mlx_loop(game->mlx);
	return (0);
}
