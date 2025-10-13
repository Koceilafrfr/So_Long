/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzidani <yzidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:37:32 by yzidani           #+#    #+#             */
/*   Updated: 2025/10/13 16:23:06 by yzidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	has_walls(char **map)
{
	int	i;
	int	len;
	int	last;

	if (!map || !map[0])
		return (0);
	len = ft_strlen(map[0]);
	last = 0;
	while (map[last])
		last++;
	last--;
	if (!first_last_row(map[0]) || !first_last_row(map[last]))
		return (0);
	i = 1;
	while (i < last)
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	first_last_row(char *row)
{
	int	i;

	i = 0;
	while (row[i])
	{
		if (row[i] != 1)
			return (0);
		i++;
	}
	return (1);
}

static int	is_rect(char **map)
{
	int	i;
	int	len;

	if (!map || !map[0])
		return (0);
	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

static int	file_name(char *filename)
{
	int	len;
	int	cmp;

	len = ft_strlen(filename);
	cmp = ft_strncmp(filename + len - 4, ".ber", 4);
	if (cmp == 0)
		return (1);
	return (0);
}

int	parsing(char **map, char *filename, t_data *game)
{
	if (!file_name(filename))
		ft_printf("erreur mom\n");
	if (!is_rect(map))
		ft_printf("erreur rect\n");
	if (!has_walls(map))
		ft_printf("erreur wall\n");
	if (!size_map(game))
		ft_printf("erreur taille\n");
	if (!content_verif(map, game))
		ft_printf("erreur content\n");
	if (!is_doable(map))
		ft_printf("erreur faisabilite\n");
	return (1);
}

/*
se servir de calloc plutot que malloc
utiliser get next line pour lire la map
*/