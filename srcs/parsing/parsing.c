/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzidani <yzidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:37:32 by yzidani           #+#    #+#             */
/*   Updated: 2025/10/13 19:51:49 by yzidani          ###   ########.fr       */
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
	cmp = ft_strncmp(&filename[len - 4], ".ber", 4);
	if (cmp == 0)
		return (1);
	return (0);
}

int	parsing(char **map, char *filename, t_data *game)
{
	if (!file_name(filename))
		return (ft_printf("Wrong file name\n"), 0);
	if (!is_doable(map))
		return (ft_printf("erreur faisabilite\n"), 0);
	if (!has_walls(map))
		return (ft_printf("erreur wall\n"), 0);
	if (!is_rect(map))
		return (ft_printf("wrong shape rect\n"), 0);
	if (!size_map(game))
		return (ft_printf("erreur taille\n"), 0);
	if (!content_verif(map, game))
		return (ft_printf("erreur content\n"), 0);
	return (1);
}