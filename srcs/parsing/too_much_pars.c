/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   too_much_pars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzidani <yzidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 20:10:02 by yzidani           #+#    #+#             */
/*   Updated: 2025/10/16 14:57:22 by yzidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_flood_fill(char **map, int y, int x, int include_exit)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'E' && !include_exit)
		return ;
	if (map[y][x] == 'P' || map[y][x] == 'C' || map[y][x] == '0'
		|| (map[y][x] == 'E' && include_exit))
		map[y][x] = 'V';
	else
		return ;
	ft_flood_fill(map, y + 1, x, include_exit);
	ft_flood_fill(map, y - 1, x, include_exit);
	ft_flood_fill(map, y, x + 1, include_exit);
	ft_flood_fill(map, y, x - 1, include_exit);
}

static int	fill_lines(int fd, char **map)
{
	int		i;
	int		len;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		map[i++] = line;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (1);
}

static int	count_lines(char *filename)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

char	**get_map(char *filename)
{
	int		fd;
	int		lines;
	char	**map;

	lines = count_lines(filename);
	if (lines == -1)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = malloc(sizeof(char *) *(lines + 1));
	if (!map)
		return (NULL);
	if (!fill_lines(fd, map))
		return (NULL);
	close(fd);
	return (map);
}
