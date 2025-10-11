/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   too_much_pars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzidani <yzidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 20:10:02 by yzidani           #+#    #+#             */
/*   Updated: 2025/10/11 21:34:30 by yzidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	fill_lines(int fd, char **map)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line[ft_strlen(line - 1)] == '\n')
			line[ft_strlen(line - 1) = '\0'];
		map[i++];
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
	if (!fill_lines(fd, map))
		return (NULL);
	close(fd);
	return (map);
}
