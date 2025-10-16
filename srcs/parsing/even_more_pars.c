/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   even_more_pars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzidani <yzidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 19:08:49 by yzidani           #+#    #+#             */
/*   Updated: 2025/10/16 14:58:16 by yzidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	check_collectibles(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_exit(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
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

	(void)game;
	map_cpy = cpy_map(map);
	if (!map_cpy)
		return (0);
	player_pos(map_cpy, &player_y, &player_x);
	if (player_x == -1 || player_y == -1)
		return (free_tab(map_cpy), 0);
	ft_flood_fill(map_cpy, player_y, player_x, 0);
	if (!check_collectibles(map_cpy))
		return (free_tab(map_cpy), 0);
	free_tab(map_cpy);
	map_cpy = cpy_map(map);
	if (!map_cpy)
		return (0);
	player_pos(map_cpy, &player_y, &player_x);
	ft_flood_fill(map_cpy, player_y, player_x, 1);
	if (!check_exit(map_cpy))
		return (free_tab(map_cpy), 0);
	free_tab(map_cpy);
	return (1);
}
