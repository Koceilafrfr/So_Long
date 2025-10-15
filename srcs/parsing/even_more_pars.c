/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   even_more_pars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzidani <yzidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 19:08:49 by yzidani           #+#    #+#             */
/*   Updated: 2025/10/15 19:17:11 by yzidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	is_all_reachable(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	ft_flood_fill(char **map, int y, int x, t_data *game)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'E' || map[y][x] == 'P' || map[y][x] == 'C'
		|| map[y][x] == '0')
		map[y][x] = 'V';
	else
		return ;
	ft_flood_fill(map, y + 1, x, game);
	ft_flood_fill(map, y - 1, x, game);
	ft_flood_fill(map, y, x + 1, game);
	ft_flood_fill(map, y, x - 1, game);
}

static void	player_pos(char **map, int *player_y, int *player_x)
{
	int	i;
	int	j;

	i = 0;
	*player_y = -1;
	*player_x = -1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*player_y = i;
				*player_x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

static char	**cpy_map(char **map)
{
	int		i;
	char	**cpy;

	i = 0;
	while (map[i])
		i++;
	cpy = malloc(sizeof(char *) * (i + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		cpy[i] = ft_strdup(map[i]);
		if (!cpy[i])
			return (NULL);
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}

int	is_doable(char **map, t_data *game)
{
	char	**map_cpy;
	int		player_x;
	int		player_y;

	map_cpy = cpy_map(map);
	if (!map_cpy)
		return (0);
	player_pos(map_cpy, &player_y, &player_x);
	if (player_x == -1 || player_y == -1)
	{
		free_tab(map_cpy);
		return (0);
	}
	ft_flood_fill(map_cpy, player_y, player_x, game);
	if (!is_all_reachable(map_cpy))
	{
		free_tab(map_cpy);
		return (0);
	}
	free_tab(map_cpy);
	return (1);
}
