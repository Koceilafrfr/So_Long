/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzidani <yzidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:35:33 by yzidani           #+#    #+#             */
/*   Updated: 2025/10/09 16:29:46 by yzidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <mlx.h>

typedef struct s_game {
	char	**map;
	void	*win;
	void	*mlx;
	void	*player_img;
	void	*wall_img;
	void	*floor_img;
	void	*exit_img;
	void	*collectible_img;

	int		moves;
	int		collectibles;
	int		height;
	int		player_x;
	int		player_y;
	int		width;
	int		exit_x;
	int		exit_y;
	int		height;
}	t_game;

#endif